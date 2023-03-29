#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_

#include <condition_variable>
#include <deque>
#include <functional>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

class ThreadPoolInterface {
public:
  virtual ~ThreadPoolInterface() {}
  virtual void Schedule(std::function<void()> task) = 0;
};

class ThreadPool : public ThreadPoolInterface {
public:
  explicit ThreadPool(int num_threads);
  ~ThreadPool();

  void Schedule(std::function<void()> task) override;

  int NumThreadsRunning() const;

private:
  void DoWork();

  bool running_;
  std::vector<std::thread> pool_;
  std::deque<std::function<void()>> task_queue_;
  mutable std::mutex mutex_;
  std::condition_variable condition_;
  int num_threads_running_; // new member variable to count the number of
                            // running threads
};

#endif // THREAD_POOL_H_