// 1214

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int D, P, Q;
	cin >> D >> P >> Q;

	if (P > Q) swap(P, Q);

	if (D % P == 0 || D % Q == 0) {
		cout << D;
	}
	else {
		int ans = (D / Q) * Q + Q;
		int tmp = ans;

		for (int i = 1; i <= tmp / Q; i++) {
			int temp = tmp - Q * i;
			if ((D - temp) % P == 0) {
				cout << D;
				return 0;
			}
			else {
				temp += ((D - temp) / P) * P + P;
			}
			if (ans == temp) break;
			ans = min(ans, temp);
		}
		cout << ans;
	}
}