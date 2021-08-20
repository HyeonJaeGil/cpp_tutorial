#include <iostream>
#include <vector>
#include <string>
#include <filesystem> //c++17

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;
using std::filesystem::recursive_directory_iterator;

int main() {
    string path = "./";

    // for (const auto & file : recursive_directory_iterator(path))
    for (const auto & file : directory_iterator(path))
        cout << file.path() << endl;

    return EXIT_SUCCESS;
}