// 11399

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int N;
	int now_num;
	priority_queue<int> pq;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> now_num;
		pq.push(now_num * -1);
	}

	int total = 0;
	int time = 0;

	while (!pq.empty()) {
		time += pq.top() * -1;
		total += time;
		pq.pop();
	}

	cout << total;
}