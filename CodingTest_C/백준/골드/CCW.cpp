// 11758

#include <iostream>

using namespace std;

int main(void) {
	int p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;
	cin >> p1_x >> p1_y >> p2_x >> p2_y >> p3_x >> p3_y;

	int result = (p2_x - p1_x) * (p3_y - p1_y) - (p3_x - p1_x) * (p2_y - p1_y);

	if (result == 0)
		cout << 0;
	else if (result > 0)
		cout << 1;
	else
		cout << -1;
}