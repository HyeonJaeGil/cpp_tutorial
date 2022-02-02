#include <iostream>
#include <vector>
#include <string>
// #include <experimental/filesystem>
#include <filesystem> //c++17
#include <set>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;
using std::filesystem::recursive_directory_iterator;

int main() {
    string path = "/home/hj/Dropbox/dataset/warehouse/210701/rgb";

    std::set<std::filesystem::path> sorted;
    for (const auto & file: directory_iterator(path))
        sorted.insert(file.path());

    for (const auto & sortedFile : sorted)
        cout << sortedFile.c_str() << endl;

    // for (const auto & file : recursive_directory_iterator(path))
    // for (const auto & file : directory_iterator(path))
    //     cout << file.path() << endl;

    return EXIT_SUCCESS;
}