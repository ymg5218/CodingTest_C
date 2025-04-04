// 1929

#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;
	vector<bool> notPrime(N + 1);
	notPrime[0] = true; notPrime[1] = true;
	for (int n{ 2 }; n < sqrt(N) + 1; n++) {
		if (notPrime[n]) continue;
		int now_num = n;
		int multi = 2;
		now_num = n * multi;
		while (now_num <= N) {
			notPrime[now_num] = true;
			multi++;
			now_num = n * multi;
		}
	}

	for (int idx = M; idx < N + 1; idx++) {
		if (!notPrime[idx]) cout << idx << endl;
	}
}