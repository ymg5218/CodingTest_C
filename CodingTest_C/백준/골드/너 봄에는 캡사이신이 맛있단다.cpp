// 15824

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define endl "\n"
#define ll long long
#define mod 1'000'000'007

using namespace std;

int N;
vector<ll> arr;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

    vector<ll> pow2(N);
    pow2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll val = arr[i] % mod;

        ll max_cnt = (val * pow2[i]) % mod;
        ll min_cnt = (val * pow2[N - 1 - i]) % mod;

        ans = (ans + max_cnt) % mod;
        ans = (ans - min_cnt + mod) % mod;
    }

    cout << ans << endl;

    return 0;
}