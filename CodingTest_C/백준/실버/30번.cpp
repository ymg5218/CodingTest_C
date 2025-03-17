// 13116

#include <iostream>

using namespace std;

int T;
int A, B;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	cin >> T;

	for (int i{ 0 }; i < T; i++) {
		cin >> A >> B;
		
		while (A != B) {
			if (A < B) B /= 2;
			else A /= 2;
		}

		cout << A * 10<< "\n";
	}
	
}