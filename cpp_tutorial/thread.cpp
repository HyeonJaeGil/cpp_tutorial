#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

using namespace std;

mutex mtx;

int main() 
{

	//atomic<int> shared_memory(0);
	int shared_memory(0);

	auto count_func = [&] () {
		for (int i = 0; i < 1000; ++i) 
		{
			this_thread::sleep_for(chrono::milliseconds(1));

			///*using lock and unlock */
			//mtx.lock();
			//shared_memory++;
			//mtx.unlock();

			///*using lock_guard */
			//std::lock_guard<std::mutex> lock(mtx);
			//shared_memory++;

			/*using scoped_lock (c++17)*/
			std::scoped_lock lock(mtx); 
			shared_memory++;

		}
	};

	thread t1 = std::thread(count_func);
	thread t2 = std::thread(count_func);

	t1.join();
	t2.join();

	cout << "After" << endl;
	cout << shared_memory << endl;

	return 0;
}