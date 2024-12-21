// 14503

#include <iostream>

using namespace std;

// �ݽð����. �� -> �� -> �� -> ��
int d_row[] = { -1, 0, 1, 0 };
int d_col[] = { 0, 1, 0, -1 };
int board[50][50];
int cnt = 0;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int N, M;
	cin >> N >> M;

	int now_row, now_col, dir;
	int next_row, next_col, next_dir;
	cin >> now_row >> now_col >> dir;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> board[row][col];
		}
	}
	bool can_forward;
	bool logic_finished = false;
	
	while (!logic_finished) {
		// ���� ��ġ�� ���̸� ����
		if (board[now_row][now_col] == 1) break;
		can_forward = false;
		
		// ���� ĭ û��
		board[now_row][now_col] = 2;
		cnt++;

		// �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �����ϴ��� Ȯ��.
		// �ݽð���� ������� Ȯ��.
		next_dir = dir;
		for (int i = 1; i <= 4; i++) {
			next_dir = (next_dir + 3) % 4;
			next_row = now_row + d_row[next_dir];
			next_col = now_col + d_col[next_dir];
			// û�ҵ��� ���� �� ĭ�� �����Ѵٸ�
			// 1. ���� û���� ĭ�� ��ǥ�� ����
			// 2. ���� ������ ������ dir�� ����
			if (board[next_row][next_col] == 0) {
				now_row = next_row;
				now_col = next_col;
				dir = next_dir;
				can_forward = true;
				break;
			}
		}
		if (can_forward) continue;

		// �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �������� �ʴ´ٸ�
		// ���� �������� �ٲ�
		dir = (dir + 2) % 4;

		while (true) {
			// ���� �������� ���ư���
			now_row += d_row[dir];
			now_col += d_col[dir];
			// ���� ������ ���� ���̶�� ��ü ������ �����Ѵ�.
			if (board[now_row][now_col] == 1) {
				logic_finished = true;
				break;
			}
			if (board[now_row][now_col] == 0) {
				dir = (dir + 2) % 4;
				break;
			}

			// ������ ������ �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �����ϴ��� Ȯ��.
			// �ݽð���� ������� Ȯ��.
			next_dir = (dir + 2) % 4;
			for (int i = 1; i <= 4; i++) {
				next_dir = (next_dir + 3) % 4;
				next_row = now_row + d_row[next_dir];
				next_col = now_col + d_col[next_dir];
				// û�ҵ��� ���� �� ĭ�� �����Ѵٸ�
				// 1. ���� û���� ĭ�� ��ǥ�� ����
				// 2. ���� ������ ������ dir�� ����
				if (board[next_row][next_col] == 0) {
					now_row = next_row;
					now_col = next_col;
					dir = next_dir;
					can_forward = true;
					break;
				}
			 }
				
			// �����ϴٰ� �ֺ��� �� ĭ�� ������ Ȯ���ߴٸ� �ݺ��� Ż��
			if (can_forward) break;

			// �߰����� ���ߴٸ� ��� ����
			else continue;
		}
	
	}	
	cout << cnt << '\n';
}