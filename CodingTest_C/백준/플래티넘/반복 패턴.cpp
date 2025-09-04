// 16229

#include <iostream>
#include <vector>
#define endl "\n"
#define ll long long

using namespace std;

vector<int> Z(const string S, const int size) {
	vector<int> z(size, 0);
	for (int i = 1, l = 0, r = 0; i < size; i++) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);
		
		while (i + z[i] < size && S[i + z[i]] == S[z[i]])
			z[i]++;
		
		if (r < i + z[i] - 1)
			r = i + z[i] - 1, l = i;
	}

	return z;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;
	auto z = Z(S, N);
	vector<int> cands;
	cands.push_back(N);
	for (int i = 0; i < N; i++) {
		if (i + z[i] == N) cands.push_back(i);
	}

	int max_len = 0;
	ll T = (ll)N + K;
	for (int p : cands) {
		ll t = T / p;
		if (t >= 2 && t * p >= N)
			max_len = max(max_len, p);
	}
	
	cout << max_len << endl;
}