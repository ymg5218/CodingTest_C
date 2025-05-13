// 2217
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(NULL);
	int N;
	cin >> N;

	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		int r;
		cin >> r;
		pq.push(r);
	}
	int num = 0;
	int total = 0;
	int max_total = 0;
	while (!pq.empty()) {
		int now_w = pq.top();
		pq.pop();
		num++;
		int now_total = now_w * num;
		if (now_total / num > now_w) {
			break;
		}
		total = now_total;
		max_total = max(max_total, total);
	}
	cout << max_total << endl;
}