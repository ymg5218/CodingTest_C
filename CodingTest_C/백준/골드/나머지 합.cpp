// 10986

#include <iostream>
#include <vector>
#define endl "\n"
#define ll long long

using namespace std;

int N;
ll M;
vector<ll> prefix_mod;
vector<ll> prefix_mod_cnt; // ��� Prefix ������ ��, ���� ���� M���� ������ ���� �� �������� ����� ���� Prefix ������ �� ������ ��� ����

void solution() {
	ll answer = prefix_mod_cnt[0]; // ���� ��ü�� 0���� �̹� �������� ����� ����

	for (int i = 0; i < M; i++) {
		answer += (prefix_mod_cnt[i] * (prefix_mod_cnt[i] - 1)) / 2; // �������� ���� ���������� ���� 0�̴�, �ش� ������ ���� ���ϱ�
	}

	cout << answer << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	

	cin >> N >> M;
	prefix_mod.resize(N, 0);
	prefix_mod_cnt.resize(M, 0);

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (i == 0) prefix_mod[i] = x % M;
		else {
			prefix_mod[i] = (prefix_mod[i - 1] + x) % M;
		}
		prefix_mod_cnt[prefix_mod[i]]++;
	}

	solution();
}