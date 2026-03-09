// 11213

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> cnt(6, {0, 0});

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		cnt[x - 1].first++;
		cnt[x - 1].second = i + 1;
	}
	for (int i = 5; i >= 0; i--) {
		if (cnt[i].first == 1) {
			cout << cnt[i].second;
			return 0;
		}
	}
	cout << "none";
	return 0;
}