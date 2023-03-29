#include <string>

class Name
{
private:
    std::string firstname {};
    std::string lastname {};
public:
    Name(std::string first, std::string second)
        :firstname(first), lastname(second) {};
    Name()=default;

    bool operator < (const Name& name)
    {
        return lastname < name.lastname ||
            ((lastname == name.lastname) && (firstname < name.firstname));
    }

    std::string getFirstName() const {return firstname;}
    std::string getSecondName() const {return lastname;}

    friend std::ostream& operator << (std::ostream& os, const Name& name);

};


std::ostream& operator << (std::ostream& os, const Name& name)
{
    os << name.getFirstName() <<" ," << name.getSecondName();
    return os;
}