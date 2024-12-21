// 14503

#include <iostream>

using namespace std;

// 반시계방향. 북 -> 동 -> 남 -> 서
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
		// 현재 위치가 벽이면 종료
		if (board[now_row][now_col] == 1) break;
		can_forward = false;
		
		// 현재 칸 청소
		board[now_row][now_col] = 2;
		cnt++;

		// 주변 4칸 중 청소되지 않은 빈 칸이 존재하는지 확인.
		// 반시계방향 순서대로 확인.
		next_dir = dir;
		for (int i = 1; i <= 4; i++) {
			next_dir = (next_dir + 3) % 4;
			next_row = now_row + d_row[next_dir];
			next_col = now_col + d_col[next_dir];
			// 청소되지 않은 빈 칸이 존재한다면
			// 1. 다음 청소할 칸의 좌표로 갱신
			// 2. 현재 전진한 방향을 dir에 갱신
			if (board[next_row][next_col] == 0) {
				now_row = next_row;
				now_col = next_col;
				dir = next_dir;
				can_forward = true;
				break;
			}
		}
		if (can_forward) continue;

		// 주변 4칸 중 청소되지 않은 빈 칸이 존재하지 않는다면
		// 후진 방향으로 바꿈
		dir = (dir + 2) % 4;

		while (true) {
			// 후진 방향으로 나아가기
			now_row += d_row[dir];
			now_col += d_col[dir];
			// 만약 후진한 곳이 벽이라면 전체 로직을 종료한다.
			if (board[now_row][now_col] == 1) {
				logic_finished = true;
				break;
			}
			if (board[now_row][now_col] == 0) {
				dir = (dir + 2) % 4;
				break;
			}

			// 후진한 방향의 주변 4칸 중 청소되지 않은 빈 칸이 존재하는지 확인.
			// 반시계방향 순서대로 확인.
			next_dir = (dir + 2) % 4;
			for (int i = 1; i <= 4; i++) {
				next_dir = (next_dir + 3) % 4;
				next_row = now_row + d_row[next_dir];
				next_col = now_col + d_col[next_dir];
				// 청소되지 않은 빈 칸이 존재한다면
				// 1. 다음 청소할 칸의 좌표로 갱신
				// 2. 현재 전진한 방향을 dir에 갱신
				if (board[next_row][next_col] == 0) {
					now_row = next_row;
					now_col = next_col;
					dir = next_dir;
					can_forward = true;
					break;
				}
			 }
				
			// 후진하다가 주변에 빈 칸이 있음을 확인했다면 반복문 탈출
			if (can_forward) break;

			// 발견하지 못했다면 계속 후진
			else continue;
		}
	
	}	
	cout << cnt << '\n';
}