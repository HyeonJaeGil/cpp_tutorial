#include <iostream>
#include <mutex>
#include <atomic>
#include <thread>

using namespace std;

int main()
{
	int shared_memory(0);

	mutex mtx;
	auto count_func = [&]()
	{
		for (int i = 0; i < 1000; ++i)
		{
			// std::lock_guard<mutex> lock(mtx);	
			std::scoped_lock<mutex> lock(mtx);		// c++17
			shared_memory++;
		}
	};

	std::thread t1 = std::thread(count_func);
	std::thread t2 = std::thread(count_func);

	t1.join();
	t2.join();

    cout << "After" << endl;
	cout << shared_memory << '\n';
}