// 1065

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	 
	if (N < 100) {
		cout << N << endl;
		return 0;
	}

	int n = 100;
	int cnt = 99;
	while (n <= N) {
		vector<int> digit;
		int now_num = n;
		while (now_num > 0) {
			digit.push_back(now_num % 10);
			now_num /= 10;
		}

		bool is_valid = true;
		int gap = digit[1] - digit[0];
		for (int i = 1; i < digit.size() - 1; i++) {
			int now_gap = digit[i + 1] - digit[i];
			if (gap != now_gap) {
				is_valid = false;
				break;
			}
		}
		
		if (is_valid) {
			cnt++;
		}

		n++;
	}
	cout << cnt;
}