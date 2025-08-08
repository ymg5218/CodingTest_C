#include <iostream>
#include <vector>
#include <string>
#define endl "\n"

using namespace std;

int solution(int n) {
	int now = n;
	vector<int> stack;
	while (n > 0) {
		stack.push_back(n % 2);
		n /= 2;
	}

	int n_cnt = 0;
	while (!stack.empty()) {
		if (stack.back() == 1) n_cnt++;
		stack.pop_back();
	}

	while (true) {
		now ++;
		int temp = now;
		
		while (temp > 0) {
			stack.push_back(temp % 2);
			temp /= 2;
		}

		int cnt = 0;
		while (!stack.empty()) {
			if (stack.back() == 1) cnt++;
			stack.pop_back();
		}

		if (n_cnt == cnt) return now;
	}
}

int main(void) {
	int n = 78;
	cout << solution(n) << endl;
}