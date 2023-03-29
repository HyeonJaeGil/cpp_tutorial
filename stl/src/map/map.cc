#include <iostream>
#include <map>
#include "../../include/Name.h"


int main(){
    Name me("hyeonjae", "gil");
    Name company("jay", "gil");

    std::cout << (me < company) << std::endl;
    std::cout << (company < me) << std::endl;

    std::map<std::string, size_t> people{{"jay", 26}, {"hyeonjae", 26}, std::make_pair("gil", 25)};
    auto new_people {people}; //copy
    std::map<std::string, size_t> new_new_people 
                        {std::begin(people), --std::end(people)};

    std::cout << people.size() << std::endl;
    std::cout << new_new_people.size() << std::endl;

    std::string key {};
    try{
        key = "jay";
        auto value = people.at(key);
        std::cout << "key: " << key << ", age: " << value << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n'
            << key << " was not found." << std::endl;
    }

    if(people.erase(key))
        std::cout << key << " removed" << std::endl;

    std::cout << people.size() << std::endl;

    auto iter = people.erase(std::begin(people), std::end(people));

    std::cout << people.size() << std::endl;


}