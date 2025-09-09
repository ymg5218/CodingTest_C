// 1911

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long

using namespace std;

ll N, L;
vector<pair<ll, ll>> list;

ll solution() {
	ll total_cnt = 0;
	
	ll prev_e = -1;
	for (const auto& p : list) {
		auto [s, e] = p;
		if (prev_e + 1 > s) {
			s = prev_e;
			if (s >= e) continue;
		}
			
		
		ll len = e - s;
		ll now_cnt = 0;
		now_cnt += len / L;
		if (len % L != 0) 
			now_cnt++;
		
		prev_e = s + now_cnt * L;
		total_cnt += now_cnt;
	}

	return total_cnt;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		ll s, e;
		cin >> s >> e;
		list.push_back({ s, e });
	}
	sort(list.begin(), list.end());
	cout << solution() << endl;
}