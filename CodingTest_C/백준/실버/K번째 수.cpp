// 11004

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, K;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> N >> K;
	vector<int> bkt(N);
	for (int i = 0; i < N; i++) {
		cin >> bkt[i];
	}
	sort(bkt.begin(), bkt.end());
	cout << bkt[K - 1];
}