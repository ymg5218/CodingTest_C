// 16953

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	long long A, B;
	cin >> A >> B;

	queue<pair<long long, long long>> q;
	q.push(make_pair(A, 1));

	long long now_num;
	long long now_op_cnt;
	while (true) {
		if (q.empty()) {
			cout << -1;
			break;
		}
		now_num = q.front().first;
		now_op_cnt = q.front().second;
		q.pop();
		if (now_num * 2 == B or now_num * 10 + 1 == B) {
			cout << now_op_cnt + 1;
			break;
		}
		if (now_num * 2 <= B) {
			q.push(make_pair(now_num * 2, now_op_cnt + 1));
		}
		if (now_num * 10 + 1 <= B) {
			q.push(make_pair(now_num * 10 + 1, now_op_cnt + 1));
		}
	}
}