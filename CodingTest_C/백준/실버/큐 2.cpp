// 18258

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	string command;
	int N;
	int num;
	queue<int> q;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> num;
			q.push(num);
		}
		else {
			if (command == "front") {
				if (q.empty()) cout << -1 << '\n';
				else cout << q.front() << '\n';
			}
			else if (command == "back") {
				if (q.empty()) cout << -1 << '\n';
				else cout << q.back() << '\n';
			}
			else if (command == "size") {
				cout << q.size() << '\n';
			}
			else if (command == "pop") {
				if (q.empty()) cout << -1 << '\n';
				else {
					cout << q.front() << '\n'; q.pop();
				}
			}
			else if (command == "empty") {
				if (q.empty()) cout << 1 << '\n';
				else cout << 0 << '\n';
			}
			else {
				cout << "유효 커맨더 아님" << '\n';
			}
		}
	}
	
}