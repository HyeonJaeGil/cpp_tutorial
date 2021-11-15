#include <iostream>
#include <string>
#include <memory>
#include <initializer_list>
#include <vector>
#include <cassert>


template <typename T, int Row, int Col>
class Matrix
{
    std::vector<T> data;
public:
    Matrix()
        : data(Row*Col)
    {
        std::cout << "constructor called" << std::endl;
        std::cout << "data size : " << data.size() << std::endl;
    }

    T getValue(int row, int col) const 
    {
        assert(row <= Row); assert(col <= Col);
        int index = (row-1) * Row + (col-1);
        return data[index];
    }

};

template <typename T, int Size>
using Square = Matrix<T, Size, Size>;


template <typename T, int Length>
using Vector = Matrix<T, Length, 1>;



int main(){

    std::cout << '\n';
    Matrix<int, 3, 3> matrix_3_3;

    return 0;
}