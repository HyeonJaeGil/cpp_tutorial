#include <iostream>
#include <utility>
#include <string>
#include <tuple>
#include "../../include/Name.h"


int main(){

    std::pair<std::string, std::string> my_pair = std::make_pair("first", "second");
    std::pair<std::string, std::string> new_pair(my_pair); 

    std::pair<Name, Name> couple{ std::piecewise_construct, 
        std::forward_as_tuple("hyeonjae", "gil"),
        std::forward_as_tuple("jay", "gil")};


    std::pair<Name, Name> test(Name("fr", "sc"), Name("fr", "sc"));

    auto test2 = std::forward_as_tuple("first", "second");

    // auto my_tuple = std::make_tuple(Name("fr", "sc"), Name("fr", "sc"));
    auto my_tuple = std::make_tuple(Name("fr", "sc"),23);
    std::cout << std::get<0>(my_tuple) << std::endl;
    std::cout << std::get<int>(my_tuple) << std::endl;

    Name name{};
    int age{};
    // std::tie(name, age) = my_tuple;
    std::tie(name, std::ignore) = my_tuple;

    std::cout << name << ", " << age << std::endl;

}