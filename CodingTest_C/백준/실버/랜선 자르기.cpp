// 1654

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int K, N;
	cin >> K >> N;

	int* LAN = new int[K];
	long long now_LAN;
	long long left = 1;
	long long right = 0;
	for (int i = 0; i < K; i++) {
		cin >> now_LAN;
		LAN[i] = now_LAN;
		right = max(right, now_LAN);
	}

	long long mid;
	long long cutted_cnt;
	long long max_length = 0;
	while (left <= right) {
		cutted_cnt = 0;
		mid = (left + right) / 2;
		if (mid == 0) {
			break;
		}
		for (int i = 0; i < K; i++) {
			cutted_cnt += LAN[i] / mid;
		}

		// �߸� ������ ��ǥ���� ���ڸ� -> mid ���� ���ҽ�Ŵ
		if (cutted_cnt < N) {
			right = mid - 1;
		}
		// �߸� ������ ��ǥ ������ �ʰ��� -> mid�� ������Ŵ
		// �߸� ������ ��ǥ ������ ������ -> �ִ� ���̸� ���غ��� ���� mid�� ������Ŵ
		else {
			max_length = max(max_length, mid);
			left = mid + 1;
		}
	}

	cout << max_length;
}