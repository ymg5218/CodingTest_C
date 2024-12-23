// 14891

#include <iostream>
#include<string>
#include <deque>
using namespace std;

deque<char> cogs[4];

void solution(int cog_num, int dir) {
	// 톱니를 맨 앞이나 맨 뒤로 옮길 때 담아두기 위한 임시변수
	char temp;

	int rotate_dir[4]{ 0 };
	rotate_dir[cog_num] = dir;
	// 왼쪽 톱니들 확인
	for (int idx = cog_num - 1; idx >= 0; idx--) {
		// 현재 톱니와 왼쪽 톱니가 맞물린 곳의 양 극이 같으면 해당 왼쪽 톱니부터는 움직이지 않음
		if (cogs[idx + 1][6] == cogs[idx][2]) break;
		// 맞물린 극이 서로 다르다면, 왼쪽 톱니는 현재 톱니의 회전 방향과 반대 방향으로 회전할 예정
		rotate_dir[idx] = rotate_dir[idx + 1] * -1;
	}

	// 오른쪽 톱니들 확인
	for (int idx = cog_num + 1; idx <= 3; idx++) {
		// 현재 톱니와 오른쪽 톱니가 맞물린 곳의 양 극이 같으면 해당 오른쪽 톱니부터는 움직이지 않음
		if (cogs[idx - 1][2] == cogs[idx][6]) break;
		// 맞물린 극이 서로 다르다면, 오른쪽 톱니는 현재 톱니의 회전 방향과 반대 방향으로 회전할 예정
		rotate_dir[idx] = rotate_dir[idx - 1] * -1;
	}

	for (int idx = 0; idx < 4; idx++) {
		// 회전하지 않음
		if (rotate_dir[idx] == 0) continue;

		// 시계 방향으로 회전
		else if (rotate_dir[idx] == 1) {
			temp = cogs[idx].back();
			cogs[idx].pop_back();
			cogs[idx].push_front(temp);
		}
		// 반시계 방향으로 회전
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
	// 최종 점수
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

	// 결과를 점수로 최종 환산
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