#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <random>

#include "../include/Customer.h"
#include "../include/Checkout.h"

using std::string;
using distribution = std::uniform_int_distribution<>;


void histogram(const std::vector<int>& v, int min)
{
    string bar(60, '*');
    for (size_t i {}; i < v.size(); ++i)
    {
        std::cout << std::setw(3) << i*min << " "
            << std::setw(4) << v[i] << " "
            << bar.substr(0, v[i])
            << (v[i] > static_cast<int>(bar.size()) ? "..." : "")
            << std::endl;
    }

}

int main()
{
    std::random_device random_n;

    int service_t_min {2}, service_t_max {15};
    distribution service_t_d {service_t_min, service_t_max};

    int min_customers {15}, max_customers {20};
    distribution n_1st_customers_d {min_customers, max_customers};

    int min_arr_interval {1}, max_arr_interval {5};
    distribution arrival_interval_d {min_arr_interval, max_arr_interval};

    size_t n_checkouts {};
    std::cout << "the number of checkouts: ";
    std::cin >> n_checkouts;

    if(!n_checkouts)
    {
        std::cout << "the number of checkouts should be more than 1, setting n_checkout to 1.";
        n_checkouts = 1;
    }

    std::vector<Checkout> checkouts {n_checkouts};
    std::vector<int> service_times(service_t_max-service_t_min+1); //size

    int count {n_1st_customers_d(random_n)};
    std::cout << "1st customer number: " << count << std::endl;
    int added {};
    int service_t {};
    while (added++ < count)
    {
        service_t = service_t_d(random_n);
        std::min_element(std::begin(checkouts), std::end(checkouts))->add(Customer(service_t));
        ++service_times[service_t - service_t_min];
    }

    size_t time {};
    const size_t total_time {600};
    size_t longest_q {};

    int new_cust_interval {arrival_interval_d(random_n)};

    while (time < total_time)
    {
        ++time;

        if(--new_cust_interval == 0)
        {
            service_t = service_t_d(random_n);
            std::min_element(std::begin(checkouts), std::end(checkouts))->add(Customer((service_t)));
            ++service_times[service_t - service_t_min];

            for (auto& checkout : checkouts)
                longest_q = std::max(longest_q, checkout.qlength());
            new_cust_interval = arrival_interval_d(random_n);
        }

        for(auto& checkout : checkouts)
            checkout.time_increment();
    }

    std::cout << "longest q: " << longest_q << std::endl;
    std::cout << "histogram: \n";
    histogram(service_times, service_t_min);

    std::cout << "total customers: "
            << std::accumulate(std::begin(service_times), std::end(service_times), 0)
            << std::endl;

}