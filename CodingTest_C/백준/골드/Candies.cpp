// 25650

#include <iostream>
#include <deque>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

int n, x;
deque<int> dq;
int res = 0;

void inter_adj() {
	for (int i = 0; i < n; i++) {
		int now;
		cin >> now;
		if (dq.empty()) {
			dq.push_back(now);
			continue;
		}
		if (dq.back() == now or dq.back() + now == x) {
			dq.pop_back();
			res++;
		}
		else
			dq.push_back(now);
	}
}

void front_back_adj() {
	while (dq.size() > 1 && (dq.front() == dq.back() or dq.front() + dq.back() == x)) {
		dq.pop_back();
		dq.pop_front();
		res++;
	}
}

void init() {
	cin >> n >> x;
}

int main() {
	FASTIO;
	init();
	inter_adj();
	front_back_adj();
	cout << res << endl;
}