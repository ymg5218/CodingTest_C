// 8582

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

vector<int> h;
vector<int> left_h;
vector<int> right_h;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n;
	cin >> n;
	h.resize(n);
	left_h.resize(n, 0);
	right_h.resize(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	left_h[0] = h[0]; right_h[n - 1] = h[n - 1];
	for (int i = 1; i < n; i++) {
		int l_idx = i;
		int r_idx = n - i - 1;

		left_h[l_idx] = max(left_h[l_idx - 1], h[l_idx]);
		right_h[r_idx] = max(right_h[r_idx + 1], h[r_idx]);
	}

	for (int i = 0; i < n; i++) {
		cout << left_h[i] << " " << right_h[i] << endl;
	}
}