// 1202

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"
#define ll long long

using namespace std;


bool compare(const pair<int, int>& a, const pair<int, int>& b){
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

vector<pair<int, int>> jewels;
vector<int> backpacks;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	backpacks.resize(K);

	for (int i = 0; i < N; i++) {
		int now_weight, now_price;
		cin >> now_weight >> now_price;
		jewels.push_back(make_pair(now_weight, now_price));
	}
	sort(jewels.begin(), jewels.end(), compare);

	for (int i = 0; i < K; i++) {
		cin >> backpacks[i];
	}
	sort(backpacks.begin(), backpacks.end());
	
	ll res = 0;

	priority_queue<int> pq;
	int j = 0;
	for (int i = 0; i < K; i++) {
		while (j < N) {
			if (jewels[j].first <= backpacks[i]) {
				pq.push(jewels[j].second);
				j++;
			}
			else
				break;
		}
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}
	
	cout << res << endl;
}