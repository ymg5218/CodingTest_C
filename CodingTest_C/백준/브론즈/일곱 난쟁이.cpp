// 2309

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int sum = 0;

pair<int, int> find_fake(vector<int> height, int sum) {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - height[i] - height[j] == 100) return { i, j };
		}
	}
}

int main(void) {
	vector<int> height(9);
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}
	auto [a, b] = find_fake(height, sum);
	vector<int> cntSrt(92, 0);
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) continue;
		cntSrt[height[i]]++;
	}

	// counting sort 연습 -> 해당 문제에선 매우 비효율적임에 주의
	for (int i = 0; i < 92; i++) {
		while (cntSrt[i] > 0) {
			cout << i << endl;
			cntSrt[i]--;
		}
	}
}