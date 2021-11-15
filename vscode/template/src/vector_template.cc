#include <iostream>


template <typename T>
class Vector
{
    T* data;
    int length;
    int capacity;

public:
    Vector(int size = 1)
        :data(new T[size]), length(0), capacity(size)
        {}

    void push_back(T input)
    {}

    T operator[] (int index)
    {return data[index];}

    void remove(int index);

    int size()
    {return this->size;}

    ~Vector();


};

int main(){return 0;}