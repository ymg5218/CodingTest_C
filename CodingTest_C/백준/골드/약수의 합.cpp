// 17425

#include <iostream>
using namespace std;

long long table[1000001];

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int T;
	

	long long now_num;
	for (long long num = 1; num <= 1000000; num++) {
		now_num = num;
		while (now_num <= 1000000) {
			table[now_num] += num;
			now_num += num;
		}
	}

	for (int idx = 2; idx <= 1000000; idx++) {
		table[idx] += table[idx - 1];
	}

	cin >> T;

	int index;
	for (int i = 0; i < T; i++) {
		cin >> index;
		cout << table[index] << "\n";
	}
}