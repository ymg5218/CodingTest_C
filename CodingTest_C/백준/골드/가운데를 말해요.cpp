// 1655

#include <iostream>
#include <queue>
#define endl "\n";

using namespace std;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	priority_queue<int> min_pq;
	priority_queue<int> max_pq;
	int min_pq_length = 0;
	int max_pq_length = 0;

	int N;
	int num;

	cin >> N;
	while (N > 0) {
		cin >> num;
		if (max_pq_length - min_pq_length == 1) {
			min_pq.push(num * -1);
			min_pq_length++;
		}
		else {
			max_pq.push(num);
			max_pq_length++;
		}
		
		if (min_pq_length > 0) {
			if (max_pq.top() > min_pq.top() * -1) {
				int swap;
				swap = max_pq.top(); max_pq.pop();
			
				max_pq.push(min_pq.top() * -1);
				min_pq.pop(); min_pq.push(swap * -1);
			}
		}
		
		cout << max_pq.top() << endl;

		N--;
	}
}