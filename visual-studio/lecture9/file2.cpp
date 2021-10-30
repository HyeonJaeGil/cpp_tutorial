#include "coordin.h"
#include<cmath>
#include <iostream>

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