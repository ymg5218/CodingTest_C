// 1539

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

#define endl "\n"
#define ll long long

using namespace std;

unordered_map<int, int> height;
set<int> inserted;


int getHeight(int x) {
	auto it = inserted.lower_bound(x);
	
	int left = 0, right = 0;
	if (it != inserted.begin()) {
		auto prev_it = prev(it);
		left = height[*prev_it];
	}
	if (it != inserted.end()) {
		right = height[*it];
	}

	int h = max(left, right) + 1;
	height[x] = h;
	inserted.insert(x);

	return height[x];
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		sum += getHeight(x);
	}

	cout << sum;
}