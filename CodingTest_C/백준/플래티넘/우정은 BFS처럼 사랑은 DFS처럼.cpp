// 30466

#include <iostream>
#define endl "\n"
#define ll long long

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	ll N;
	cin >> N;
	ll m = N / 2;
	cout << 2 * (m - 1) * (N - m - 1) << endl;
	for (int i = 2; i <= m + 1; i++)
		cout << i - 1 << " " << i << endl;
	
	for (int i = m + 2; i <= N; i++) {
		cout << 1 << " " << i << endl;
	}
}