#include "thread_pool.h"

#include <iostream>

int main() {
  // Create a thread pool with n threads
  ThreadPool thread_pool(20);

  // Start a monitoring thread that displays the number of running threads every
  // second
  std::thread monitor_thread([&thread_pool]() {
    while (true) {
      std::cout << "Number of running threads: "
                << thread_pool.NumThreadsRunning() << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  });
  std::this_thread::sleep_for(std::chrono::seconds(2));

  // Schedule two tasks to the thread pool
  thread_pool.Schedule([]() {
    std::cout << "Task 1 completed" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(7));
  });
  thread_pool.Schedule([]() {
    std::cout << "Task 2 completed" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
  });

  // Wait for the tasks to complete (sleep for 1 second)
  std::this_thread::sleep_for(std::chrono::seconds(20));

  return 0;
}
