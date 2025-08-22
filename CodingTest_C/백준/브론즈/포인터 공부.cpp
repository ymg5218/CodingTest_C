// 25703

#include <iostream>
#define endl "\n"

using namespace std;

int main(void) {
	int n;
	cin >> n;
	
	int cnt = 0;
	while (cnt <= n) {
		cout << "int ";
		if (cnt == 0) cout << "a;" << endl;
		else {
			string star = "";
			for (int i = 0; i < cnt; i++) {
				star.append("*");
			}
			cout << star;
			cout << "ptr";
			if (cnt > 1) {
				cout << cnt;
			}
			cout << " = &";
			if (cnt == 1) cout << "a;" << endl;
			else {
				cout << "ptr";
				if (cnt > 2) cout << cnt - 1;
				cout << ";" << endl;
			}
		}

		
		cnt++;
	}
}