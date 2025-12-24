// 11868

#include <iostream>
using namespace std;

int main() {
	int x = 0, N, cnt;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cnt;
		x ^= cnt;
	}
	if (x == 0) cout << "cubelover";
	else cout << "koosaga";
}