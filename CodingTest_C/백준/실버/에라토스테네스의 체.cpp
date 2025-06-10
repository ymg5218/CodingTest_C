// 2960

#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"

using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;
	vector<int> numbers(N + 1);

	for (int i = 0; i <= N; i++) {
		numbers[i] = i;
	}
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (numbers[i] == -1) continue;
		numbers[i] = -1;
		cnt++;
		if (cnt == K) {
			cout << i << endl;
			return 0;
		}
		int mul = 2;
		while (i * mul <= N) {
			int now_num = i * mul;
			
			if (numbers[now_num] != -1) {
				numbers[now_num] = -1;
				cnt++;
				if (cnt == K) {
					cout << now_num << endl;
					return 0;
				}
			}
			mul++;
		}
	}
	cout << -1;
}