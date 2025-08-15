// 2490

#include <iostream>

#define endl "\n"

using namespace std;

int main(void) {
	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int x;
			cin >> x;
			if (x == 0) cnt++;
		}
		if (cnt == 0) cout << "E" << endl;
		else if (cnt == 1) cout << "A" << endl;
		else if (cnt == 2) cout << "B" << endl;
		else if (cnt == 3) cout << "C" << endl;
		else cout << "D" << endl;
	}
}