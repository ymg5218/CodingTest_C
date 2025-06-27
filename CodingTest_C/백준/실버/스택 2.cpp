// 28278

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> stack;
	int cnt = 0;

	while (N--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int num;
			cin >> num;
			stack.push_back(num);
			cnt++;
		}
		else if (cmd == 2) {
			if (stack.empty()) 
				cout << -1 << endl;
			else {
				cout << stack.back() << endl;
				stack.pop_back();
				cnt--;
			}
		}
		else if (cmd == 3) {
			cout << cnt << endl;
		}
		else if (cmd == 4) {
			if (stack.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (cmd == 5) {
			if (stack.empty())
				cout << -1 << endl;
			else {
				cout << stack.back() << endl;
			}
		}
	}
}