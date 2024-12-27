// 1789

#include <iostream>
using namespace std;

int main(void) {
	long long S;
	cin >> S;

	long long now_num = 1;

	while (true) {
		S -= now_num;
		if (S <= now_num) break;
		now_num++;
	}
	cout << now_num;
}