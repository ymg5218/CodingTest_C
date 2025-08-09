// 2609

#include <iostream>
#include <cmath>
#define endl "\n"
using namespace std;

int gcd(int a, int b) {
	int c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b, int gcd) {
	return a * b / gcd;
}

int main(void) {
	int a, b;
	cin >> a >> b;

	int g = gcd(a, b);
	int l = lcm(a, b, g);
	cout << g << endl;
	cout << l << endl;
}