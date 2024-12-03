// 1475

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	int result[9]{0};
	int now_num;
	for (int idx = 0; idx < s.size(); idx++) {
		now_num = int(s[idx] - '0');
		if (now_num == 9) result[6]++;
		else result[now_num]++;
	}

	result[6] = result[6] / 2 + result[6] % 2;
	
	int max_num = result[0];
	for (int i = 0; i < (sizeof(result) / sizeof(*result)); i++) {
		max_num = max(max_num, result[i]);
	}
	cout << max_num;
}