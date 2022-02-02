#include <iostream>

template<typename T, int N>
class array
{
private:
    T data[N];

public:
    array(T (&arr)[N]) 
    {
        for (int i = 0; i < N; i++) {
            data[i] = arr[i];
        }
    }
    
    void print()
    {
        for (int i = 0; i < N; i++) {
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    int arr[5] = {1,2,3,4,5};

    array<int, 5> int_array(arr);
}