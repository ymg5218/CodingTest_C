// 2170

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
vector<pair<int, int>> lines;

int solution() {
	int total_len = 0;

	int left = lines[0].first;
	int right = lines[0].second;
	total_len = right - left;

	for (int i = 1; i < N; i++) {
		auto [now_left, now_right] = lines[i];
		if (right >= now_left) {
			total_len += max(now_right - right, 0);
			right = max(right, now_right);
		}

		else {
			total_len += (now_right - now_left);
			left = now_left;
			right = now_right;
		}
	}

	return total_len;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	lines.resize(N);
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		lines[i] = { start, end };
	}

	sort(lines.begin(), lines.end());

	cout << solution() << endl;
}