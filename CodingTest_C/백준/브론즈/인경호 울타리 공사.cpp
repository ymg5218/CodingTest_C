// 33923

#include <iostream>
#include <cmath>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	if (N != M) {
		cout << pow(min(N, M) - 1, 2) << endl;
	}
	else {
		cout << 1 + pow(N - 2, 2) << endl;
	}
}