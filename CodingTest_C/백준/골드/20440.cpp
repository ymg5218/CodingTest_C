// 20440

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

int N;
vector<pair<int, int>> timestamp;

void init() {
	cin >> N;
	timestamp.resize(N);
	for (int i = 0; i < N; i++)
		cin >> timestamp[i].first >> timestamp[i].second;

	sort(timestamp.begin(), timestamp.end());
}

void solution() {
	priority_queue<int> pq;
	int start = timestamp[0].first, end = timestamp[0].second;
	int cnt = 1;
	pq.push(end);
	for (int i = 1; i < N; i++) {
		auto [now_s, now_e] = timestamp[i];
		if (now_e <= end) {
			cnt++;
			start = now_s;
			end
		}
		else {						// now_e > end
			if (start > now_s) {	// 기존의 시작점이 현재 ㅅ

			}
		}
	}
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	init();
	solution();
}