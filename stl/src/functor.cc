#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


template <typename T>
struct product 
{
    product(T& storage)
        :value(storage) {}
    // { std::cout << "address: " << &value << std::endl; }

    template <typename V>
    void operator()(V& v) {
    value *= v;
    }

    T& value;
};

class increment
{
private:
    int num;
public:
    increment(int n=10) : num(n) {  }
  
    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};
  
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    transform(arr, arr+n, arr, increment());
    // transform(arr, arr+n, arr, increment(5));
  
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    
    std::cout << std::endl;

    std::vector<int> my_vector {1,2,3,4,5};
    int total_elements {1};
    for_each(std::begin(my_vector), std::end(my_vector), 
                product<int>(total_elements));

    std::cout << total_elements << std::endl;
    // std::cout << "address: " << &total_elements << std::endl;

}