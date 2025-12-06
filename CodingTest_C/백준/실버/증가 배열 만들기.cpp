// 27648

#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;
	
	if (M + N - 1 > K) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		int start_num = 1;
		for (int i = 0; i < N; i++) {
			int now_num = start_num;
			for (int j = 0; j < M; j++) {
				cout << now_num << " ";
				now_num++;
			}
			start_num++;
			cout << endl;
		}	
	}
}