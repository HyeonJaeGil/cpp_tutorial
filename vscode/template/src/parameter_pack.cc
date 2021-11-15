#include <iostream>

template <typename T>
void print(T arg){std::cout << arg << std::endl;}

// parameter pack, called recursively
template <typename T, typename ...Types>
void print(T arg, Types... args)
{   
    std::cout << arg << ", ";
    print(args...);
}

// Fold
template <typename... Ints>
int sum_all(Ints... num)
{
    return (num + ...);
}

int main(){

    print("char*", 10);
    std::cout << sum_all(1,2,4) << std::endl;
    return 0;
}