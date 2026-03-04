// 15903

#include <iostream>
#include <queue>
#include <vector>

#define ll long long

using namespace std;

int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> m;

	ll res = 0;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		pq.push(x);
		res += x;
	}
	
	while (m--) {
		ll x1 = pq.top(); pq.pop();
		ll x2 = pq.top(); pq.pop();
		ll sum = x1 + x2;
		res += (sum + sum - (x1 + x2));
		pq.push(sum); pq.push(sum);
	}

	cout << res;
}