#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{

    // std::vector<double> data{1.0, 2.0};
    // data.reserve(20);
    // std::cout << data.size() << std::endl;

    // std::vector<double> myvector {1, 2, 3, 4, 5};
    // myvector.reserve(20);

    // std::copy(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(), std::back_inserter(data));

    // std::copy(std::begin(data), std::end(data), std::ostream_iterator<double>(std::cout, " "));

    // for(auto& e : myvector)
    //     std::cout << e << " ";
    
    // std::cout << std::endl;

    std::vector<int> test1{1};
    std::vector<int> test2(2);

    for(auto& e : test1)
        std::cout << e << " ";  
    std::cout << std::endl;


    for(auto& e : test2)
        std::cout << e << " ";   
    std::cout << std::endl;

    return 0;
}