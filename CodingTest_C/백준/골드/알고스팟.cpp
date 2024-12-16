// 1261

#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define INF 201

using namespace std;

// µ¿ ³² ¼­ ºÏ
int d_row[] = { 0, 1, 0, -1 };
int d_col[] = { 1, 0, -1, 0 };

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int N, M;
	cin >> M >> N;

	vector<string> graph;
	vector<int> result[100];
	string s;
	for (int row = 0; row < N; row++) {
		cin >> s;
		graph.push_back(s);
		for (int col = 0; col < M; col++) {
			result[row].push_back(INF);
		}
	}
	
	queue<pair<int, int>> q;
	q.push({0, 0});
	result[0][0] = 0;
	
	int now_row, now_col;
	int next_row, next_col;
	int now_brokenCnt;
	while (!q.empty()) {
		now_row = q.front().first;
		now_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			next_row = now_row + d_row[i];
			next_col = now_col + d_col[i];
			if (0 <= next_row and next_row < N and 0 <= next_col and next_col < M) {
				{
					now_brokenCnt = result[now_row][now_col];
					if (graph[next_row][next_col] == '1') {
						if (result[next_row][next_col] > (now_brokenCnt + 1)) {
							result[next_row][next_col] = (now_brokenCnt + 1);
							q.push({ next_row, next_col });
						}
					}
					else {
						if (result[next_row][next_col] > now_brokenCnt) {
							result[next_row][next_col] = now_brokenCnt;
							q.push({ next_row, next_col });
						}
					}
				}
			}
		}
	}
	cout << result[N - 1][M - 1];
}