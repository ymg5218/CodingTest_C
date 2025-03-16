// 2110

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
vector<int> arr;;

int binary_search() {
	int installed_router;

	int left = 0; // ù ��° �� ~ ù ��° �� �Ÿ�
	int right = arr[N - 1] - arr[0]; // ù ��° �� ~ ������ �� �Ÿ�
	int mid; // ������ ���� ã��
	
	int result; // �ش��� �Ǵ� ��

	int start; // ù ��° �� ��ġ
	int now; // ������ Ȯ���� �� ��ġ

	while (left <= right) {
		int installed_router = 1; // ù ��° ���� ��ġ�ϰ� ����

		mid = (left + right) / 2;

		start = arr[0];

		// �� ������ ���� Ȯ��
		for (int i = 0; i < N; i++) {
			now = arr[i];

			// �� ������ ���� ������ mid �Ÿ��� �Ѵ��� Ȯ���� ��, �Ѵ� ���ݿ��� �����⸦ ��ġ�ϰ� �ش� ��ġ�� �ٽ� Ž�� ���� ��ġ�� ����
			if (now - start >= mid) {
				installed_router++;
				start = now;
			}
		}

		if (installed_router >= C) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return result;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	cin >> N >> C;
	
	int h;
	for (int i = 0; i < N; i++) {
		cin >> h;
		arr.push_back(h);
	}

	sort(arr.begin(), arr.end());

	cout << binary_search();

}