#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex mtx;

int main() 
{

	//const int num_pro = std::thread::hardware_concurrency();

	//cout << std::this_thread::get_id() << endl;

	//vector<std::thread> my_threads;
	//my_threads.resize(num_pro);
	//
	//// cpu usage 100%
	//for (auto &e : my_threads)
	//	e = std::thread([]() {
	//			cout << std::this_thread::get_id() << endl;
	//			while (true) {} } );

	//for (auto& e : my_threads)
	//	e.join();

	// lambda function
	auto work_func=[](const string & name)
	{
		for (int i = 0; i < 5; ++i)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));

			mtx.lock();
			cout << name << " " << std::this_thread::get_id() << "is working " << i << endl;
			mtx.unlock();
		}
	};

	std::thread t1 = std::thread(work_func, "name1");
	std::thread t2 = std::thread(work_func, "name2");

	t1.join();
	t2.join();

	return 0;
}