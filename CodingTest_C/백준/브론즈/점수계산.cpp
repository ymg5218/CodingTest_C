// 2506

#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	
	int cont_cnt = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		bool x;
		cin >> x;
		if (x == false) cont_cnt = 0;
		else cont_cnt++;
		sum += cont_cnt;
	}

	cout << sum;
}