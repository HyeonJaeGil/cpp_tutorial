#include "coordin.h"
#include <iostream>


int main() {

	using namespace std;
	rect rplace;
	polar pplace;

	rplace.x = 3.0; rplace.y = 4.0;
	pplace = rect_to_polar(rplace);
	show_polar(pplace);

	return 0;
}