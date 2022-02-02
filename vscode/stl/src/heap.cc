#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


int main()
{
    std::vector<double> numbers {2.5, 10.0, 3.5, 6.5, 8.0, 12.0, 1.5, 6.0};
    std::make_heap(std::begin(numbers), std::end(numbers));

    for(auto& number : numbers)
        std::cout << number << " ";
    std::cout << std::endl;

    numbers.push_back(11.0);
    std::push_heap(std::begin(numbers), std::end(numbers));

    for(auto& number : numbers)
        std::cout << number << " ";    
    std::cout << std::endl;

    std::pop_heap(std::begin(numbers), std::end(numbers));
    numbers.pop_back();
    
    if(std::is_heap(std::begin(numbers), std::end(numbers)))
        std::cout << "is heap\n";
    else
        std::cout << "is not heap\n";
        
    for(auto& number : numbers)
        std::cout << number << " ";    
    std::cout << std::endl;    

}

