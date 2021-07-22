#include "Teacher.h"
#include "Student.h"


int main() {

	Student student1("Jay", 150);
	Teacher teacher1("Lee");

	std::cout << student1.getName() << std::endl;
	std::cout << teacher1.getName() << std::endl;
		
	student1.setIntel(140);
	student1.setName("Jay2");

	std::cout << student1.getName() << std::endl;
	std::cout << student1.getIntel() << std::endl;

	return 0;
}