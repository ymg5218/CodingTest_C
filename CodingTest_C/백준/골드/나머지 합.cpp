// 10986

#include <iostream>
#include <vector>
#define endl "\n"
#define ll long long

using namespace std;

int N;
ll M;
vector<ll> prefix_mod;
vector<ll> cnt;

void solution() {
	ll answer = cnt[0]; // 구간 자체가 0으로 이미 나눠지는 경우의 개수

	for (int i = 0; i < M; i++) {
		answer += (cnt[i] * (cnt[i] - 1)) / 2; // 나머지가 같은 구간끼리의 차는 0이니, 해당 조합의 개수 더하기
	}

	cout << answer << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	

	cin >> N >> M;
	prefix_mod.resize(N, 0);
	cnt.resize(M, 0);

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (i == 0) prefix_mod[i] = x % M;
		else {
			prefix_mod[i] = (prefix_mod[i - 1] + x) % M;
		}
		cnt[prefix_mod[i]]++;
	}

	solution();
}