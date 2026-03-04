// 13904

#include <iostream>
#include <queue>

using namespace std;

int N;
int d, w;
priority_queue<pair<int, int>> left_subs;
priority_queue<int> can_subs;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		left_subs.push({d, w});
	}

	int now_date = left_subs.top().first;
	int total_score = 0;

	while (now_date > 0) {
		while (!left_subs.empty() && left_subs.top().first == now_date) {
			auto [_d, _w] = left_subs.top();
			left_subs.pop();
			can_subs.push(_w);
		}
		--now_date;

		if (can_subs.empty())
			continue;
		
		total_score += can_subs.top();
		can_subs.pop();
	}

	cout << total_score;
}