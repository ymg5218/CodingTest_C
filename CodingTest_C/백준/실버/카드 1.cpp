// 1058

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (1) {
		cout << q.front() << " ";
		q.pop();
		if (!q.empty()) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		else
			break;
	}
}
