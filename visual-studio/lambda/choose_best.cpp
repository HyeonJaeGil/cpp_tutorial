#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Student
{
    std::string name{};
    int points{};
};

int main()
{
    const std::array<Student, 8> arr{
      { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 },
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    const auto best{
      std::max_element(arr.begin(), arr.end(), [](const auto& first, const auto& second) {return first.points < second.points; })
    };

    std::cout << best->name << " is the best student\n";

    return 0;
}