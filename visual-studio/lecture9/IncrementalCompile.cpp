#include <iostream>
#include <cmath>

struct polar { 
	double distance; 
	double angle; 
};

struct rect {
	double x;
	double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);


int main() {

	using namespace std;
	rect rplace;
	polar pplace;

	rplace.x = 3.0; rplace.y = 4.0;
	pplace = rect_to_polar(rplace);
	show_polar(pplace);
	
	return 0;
}


polar rect_to_polar(rect xypos) {
	using namespace std;
	polar answer;

	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);

	return answer;
}

void show_polar(polar dapos) {
	using namespace std;

	cout << "distance: " << dapos.distance << endl;
	cout << "angle:  " << dapos.angle << endl;

}