// 2961

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	vector<int> sour(N);
	vector<int> bitter(N);
	
	for (int i = 0; i < N; i++) {
		cin >> sour[i];
		cin >> bitter[i];
	}

	long long answer = 1e9;

	// ��� ����� �� (1 << N), ex) N = 3��� 001, 010, 011, 100, 101, 111
	// ��Ʈ����ŷ�� �̿��� ��� �κ� ������ Ž��
	for (int bitmask = 1; bitmask < (1 << N); bitmask++) {
		long long s = 1, b = 0;

		for (int i = 0; i < N; i++) {
			if (bitmask & (1 << i)) {
				s *= sour[i];
				b += bitter[i];
			}
		}

		answer = min(answer, abs(s - b));
	}
	cout << answer << endl;
}