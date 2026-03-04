// 1700

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, K;
vector<priority_queue<int, vector<int>, greater<int>>> list;
vector<int> seq;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> K;
	
	list.resize(K + 1);
	seq.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> seq[i];
		list[seq[i]].push(i);
	}
	
	int res = 0;
	set<int> plug;

	for (int i = 0; i < K; i++) {
		int now = seq[i];
		if (plug.size() < N) {
			if (plug.find(now) == plug.end()) {
				plug.insert(now);
			}
		}
		else {
			if (plug.find(now) != plug.end()) {
				continue;
			}
			int max_idx = -1;
			int max_seq = -1;
			for (auto x : plug) {
				while (!list[x].empty() && list[x].top() < i) {
					list[x].pop();
				}
				if (list[x].empty()) {
					max_idx = x; break;
				}
				else {
					if (max_seq < list[x].top()) {
						max_idx = x;
						max_seq = list[x].top();
					}
				}
    			}
			plug.erase(max_idx);
			plug.insert(now);
			res++;
		}
	}
	cout << res;
}