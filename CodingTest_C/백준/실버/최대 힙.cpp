// 11279

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	priority_queue<int> pQ;
	
	int N;
	cin >> N;
	
	int command;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == 0) {
			if (pQ.empty()) cout << 0 << "\n";
			else {
				cout << pQ.top() << "\n";
				pQ.pop();
			}
		}
		else pQ.push(command);
	}
}