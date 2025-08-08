// 3020

#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long

using namespace std;

int N, H;
vector <ll> top;
vector <ll> bottom;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> H;

	top.resize(H, 0);
	bottom.resize(H, 0);

	for (int i = 0; i < N; i++) { // ���̺� ����/������ �Է¹ޱ�
		int l; // ����
		cin >> l;

		if (i % 2 == 0) { // ���� 
			bottom[l - 1]++;
		}
		else {			  // ������ 
			top[l - 1]++;
		}
	}

	for (int i = H - 2; i >= 0; i--) {
		bottom[i] += bottom[i + 1];
		top[i] += top[i + 1];

	}

	ll min = 1e9;
	int cnt = 0;
	for (int b_idx = 0; b_idx < H; b_idx++) {
		int t_idx = H - b_idx - 1;
		int sum = top[t_idx] + bottom[b_idx];
		if (sum < min) {
			min = sum;
			cnt = 1;
		}
		else if (sum == min) {
			cnt++;
		}
	}
	cout << min << " " << cnt << endl;
}