// 2754

#include <iostream>
#include <cmath>
#define endl "\n"


using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	string s;
	cin >> s;
	cout << fixed;
	cout.precision(1);
	if (s == "A+") cout << 4.3 << endl;
	else if (s == "A0") cout << 4.0 << endl;
	else if (s == "A-") cout << 3.7 << endl;
	else if (s == "B+") cout << 3.3 << endl;
	else if (s == "B0") cout << 3.0 << endl;
	else if (s == "B-") cout << 2.7 << endl;
	else if (s == "C+") cout << 2.3 << endl;
	else if (s == "C0") cout << 2.0 << endl;
	else if (s == "C-") cout << 1.7 << endl;
	else if (s == "D+") cout << 1.3 << endl;
	else if (s == "D0") cout << 1.0 << endl;
	else if (s == "D-") cout << 0.7 << endl;
	else cout << 0.0 << endl;
}