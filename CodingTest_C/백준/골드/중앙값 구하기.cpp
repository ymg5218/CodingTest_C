//2696

#include <iostream>
#include <queue>
#define endl "\n"

using namespace std;

void solution() {
	int M;
	cin >> M;
	int cnt = M / 2 == 0 ? 1 : M / 2 + 1;
	cout << cnt << endl;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	priority_queue<int, vector<int>, less<int>>  max_pq;
	int min_pq_size = 0;
	int max_pq_size = 0;
	
	int x;
	cin >> x;
	int mid = x;
	cout << mid << " ";
	for (int i = 2; i <= M; i++) {
		cin >> x;
		if (i % 2 == 0) {
			if (x > mid) {
				min_pq.push(x);
				min_pq_size++;
			}
				
			else {
				max_pq.push(x);
				max_pq_size++;
			}
		}
		else {
			if (x > mid) {
				min_pq.push(x);
				min_pq_size++;
				if (min_pq_size > max_pq_size) {
					int top = min_pq.top();
					min_pq.pop();
					min_pq_size--;

					max_pq.push(mid);
					max_pq_size++;

					mid = top;
				}
				cout << mid << " ";
			}
			else {
				max_pq.push(x);
				max_pq_size++;
				if (min_pq_size < max_pq_size) {
					int top = max_pq.top();
					max_pq.pop();
					max_pq_size--;

					min_pq.push(mid);
					min_pq_size++;

					mid = top;
				}
				cout << mid << " ";
			}
		}
		if (i % 20 == 0)
			cout << endl;
	}
	cout << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		solution();
	}
}