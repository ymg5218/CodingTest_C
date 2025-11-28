// 30827

#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

struct Meeting {
	int s;
	int e;
	bool operator<(const Meeting& other) const {
		return e < other.e;
	}
};
int N, K;
vector<Meeting> meetings;
vector<int> rooms;

void init() {
	cin >> N >> K;
	rooms.assign(K, 0);
	meetings.assign(N, {});
	for (int i = 0; i < N; i++) {
		cin >> meetings[i].s >> meetings[i].e;
	}
	sort(meetings.begin(), meetings.end());
}

void solution() {
	int cnt = 0;

	for (const auto& [s, e] : meetings) {
		int max_idx = -1;
		int max_e = -1;
		for (int i = 0; i < K; i++) {
			if (s > rooms[i]) {
				if (max_e < rooms[i]) {
					max_e = rooms[i];
					max_idx = i;
				}
			}
		}
		if (max_idx != -1) {
			rooms[max_idx] = e;
			cnt++;
		}
	}
	cout << cnt << endl;
}

int main() {
	FASTIO;
	init();
	solution();
}