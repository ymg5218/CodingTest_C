// 13334

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

int n, l;
vector<pair<int, int>> locate;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> n;
	locate.resize(n);

	for (int i = 0; i < n; i++) {
		int h, o;
		cin >> h >> o;
		if (h < o)
			swap(h, o);
		locate[i] = { h, o };
	}
	
	sort(locate.begin(), locate.end());

	cin >> l;

	priority_queue<int> pq;
	int max_cnt = 0;
	for (const auto& loc : locate) {
		auto [end, start] = loc;
		if (end - start > l)
			continue;
		pq.push(-start);

		while (!pq.empty()) {
			if (-pq.top() <  end - l)
				pq.pop();
			else {
				max_cnt = max(max_cnt, (int)pq.size());
				break;
			}
		}
	}
	cout << max_cnt << endl;
}