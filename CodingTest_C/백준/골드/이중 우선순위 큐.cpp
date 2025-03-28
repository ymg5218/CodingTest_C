// 7662

#include <iostream>
#include <queue>
#include <map>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int T;
	int k;
	char command;
	int command_num;

	cin >> T;
	while (T > 0) {
		priority_queue<int,vector<int>, greater<>> min_pq;
		priority_queue<int> max_pq;
		map<int, int> numcnt;
		cin >> k;
		while (k > 0) {
			cin >> command >> command_num;
			if (command == 'I') {
				min_pq.push(command_num);
				max_pq.push(command_num);
				numcnt[command_num]++;
			}
			else {
				if (command_num == 1) {
					while (!max_pq.empty() && numcnt[max_pq.top()] == 0) {
						max_pq.pop();
					}
					if (!max_pq.empty()) {
						numcnt[max_pq.top()]--;
						max_pq.pop();
					}
					while (!min_pq.empty() && numcnt[min_pq.top()] == 0) {
						min_pq.pop();
					}
				}
				else {
					while (!min_pq.empty() && numcnt[min_pq.top()] == 0) {
						min_pq.pop();
					}
					if (!min_pq.empty()) {
						numcnt[min_pq.top()]--;
						min_pq.pop();
					}
					while (!max_pq.empty() && numcnt[max_pq.top()] == 0) {
						max_pq.pop();
					}
				}
			}
			k--;
		}

		while (!max_pq.empty() && numcnt[max_pq.top()] == 0) {
			max_pq.pop();
		}
		while (!min_pq.empty() && numcnt[min_pq.top()] == 0) {
			min_pq.pop();
		}

		if (max_pq.empty() || min_pq.empty()) {
			cout << "EMPTY" << endl;
		}
		else {
			cout << max_pq.top() <<  " " << min_pq.top() << endl;
		}
		
		T--;
	}
}