// 14891

#include <iostream>
#include<string>
#include <deque>
using namespace std;

deque<char> cogs[4];

void solution(int cog_num, int dir) {
	// ��ϸ� �� ���̳� �� �ڷ� �ű� �� ��Ƶα� ���� �ӽú���
	char temp;

	int rotate_dir[4]{ 0 };
	rotate_dir[cog_num] = dir;
	// ���� ��ϵ� Ȯ��
	for (int idx = cog_num - 1; idx >= 0; idx--) {
		// ���� ��Ͽ� ���� ��ϰ� �¹��� ���� �� ���� ������ �ش� ���� ��Ϻ��ʹ� �������� ����
		if (cogs[idx + 1][6] == cogs[idx][2]) break;
		// �¹��� ���� ���� �ٸ��ٸ�, ���� ��ϴ� ���� ����� ȸ�� ����� �ݴ� �������� ȸ���� ����
		rotate_dir[idx] = rotate_dir[idx + 1] * -1;
	}

	// ������ ��ϵ� Ȯ��
	for (int idx = cog_num + 1; idx <= 3; idx++) {
		// ���� ��Ͽ� ������ ��ϰ� �¹��� ���� �� ���� ������ �ش� ������ ��Ϻ��ʹ� �������� ����
		if (cogs[idx - 1][2] == cogs[idx][6]) break;
		// �¹��� ���� ���� �ٸ��ٸ�, ������ ��ϴ� ���� ����� ȸ�� ����� �ݴ� �������� ȸ���� ����
		rotate_dir[idx] = rotate_dir[idx - 1] * -1;
	}

	for (int idx = 0; idx < 4; idx++) {
		// ȸ������ ����
		if (rotate_dir[idx] == 0) continue;

		// �ð� �������� ȸ��
		else if (rotate_dir[idx] == 1) {
			temp = cogs[idx].back();
			cogs[idx].pop_back();
			cogs[idx].push_front(temp);
		}
		// �ݽð� �������� ȸ��
		else {
			temp = cogs[idx].front();
			cogs[idx].pop_front();
			cogs[idx].push_back(temp);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	
	int K;
	int cog_num, dir;
	string s;
	// ���� ����
	int total_score = 0;

	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int idx = 0; idx < 8; idx++) {
			cogs[i].push_back(s[idx]);
		}
	}
	
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> cog_num >> dir;
		solution(cog_num - 1, dir);
	}

	// ����� ������ ���� ȯ��
	int now_score;
	for (int i = 0; i < 4; i++) {
		if (cogs[i][0] == '1') {
			now_score = 1;
			for (int seq = 0; seq < i; seq++) {
				now_score *= 2;
			}
			total_score += now_score;
		}
	}

	cout << total_score;
}