#include "thread_pool.h"

ThreadPool::ThreadPool(int num_threads)
    : running_{true}, num_threads_running_{0} {
  for (int i = 0; i < num_threads; ++i) {
    pool_.emplace_back([this]() { ThreadPool::DoWork(); });
  }
}

ThreadPool::~ThreadPool() {
  {
    std::unique_lock<std::mutex> lock(mutex_);
    running_ = false;
  }
  condition_.notify_all();
  for (std::thread &thread : pool_) {
    thread.join();
  }
}

void ThreadPool::Schedule(std::function<void()> task) {
  {
    std::unique_lock<std::mutex> lock(mutex_);
    task_queue_.push_back(std::move(task));
  }
  condition_.notify_one();
}

int ThreadPool::NumThreadsRunning() const {
  std::unique_lock<std::mutex> lock(mutex_);
  return num_threads_running_;
}

void ThreadPool::DoWork() {
  while (running_) {
    std::function<void()> task;
    {
      std::unique_lock<std::mutex> lock(mutex_);
      condition_.wait(lock,
                      [this]() { return !task_queue_.empty() || !running_; });
      if (!running_ && task_queue_.empty()) {
        return;
      }
      task = std::move(task_queue_.front());
      task_queue_.pop_front();
      ++num_threads_running_; // increment the count of running threads
    }
    task();
    {
      std::unique_lock<std::mutex> lock(mutex_);
      --num_threads_running_; // decrement the count of running threads
    }
  }
}
