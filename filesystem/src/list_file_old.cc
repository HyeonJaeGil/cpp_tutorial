#include <iostream>
#include <vector>
#include <dirent.h>

using std::cout; using std::cin;
using std::endl; using std::vector;

int main() {
    DIR *dir; struct dirent *diread;
    vector<char *> files;

    if ((dir = opendir("./")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            files.push_back(diread->d_name);
        }
        closedir (dir);
    } else {
        perror ("opendir");
        return EXIT_FAILURE;
    }

    for (auto file : files) cout << file << "| ";
    cout << endl;

    return EXIT_SUCCESS;
}