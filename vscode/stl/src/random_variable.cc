#include <iostream>
#include <algorithm>
#include <random>

using distribution = std::uniform_int_distribution<>;

int main()
{
    std::random_device random_n;

    int time_t_min {2}, time_t_max {15};
    distribution time_dist {time_t_min, time_t_max};


    for (int i = 0; i < 10; ++i)
    {    
        auto time_t = time_dist(random_n);
        std::cout << "random time: "<< time_t << std::endl;
    }

}