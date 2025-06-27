// 13305

#include <iostream>
#include <vector>
#define endl "\n"
#define ll long long

using namespace std;

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> length(N);
	vector<int> price(N);

	for (int i = 0; i < N - 1; i++) {
		cin >> length[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}
	ll now_price = price[0];
	ll sum = now_price * length[0];
	for (int i = 1; i < N - 1; i++) {
		if (now_price > price[i])
			now_price = price[i];
		sum += now_price * length[i];
	}

	cout << sum << endl;
}