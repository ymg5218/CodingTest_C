// 3055

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

int R, C;
vector<vector<char>> graph;
vector<vector<int>> dist;
vector<vector<int>> water_time;   
queue<pair<int, int>> water;
int d_row[] = { 0, 1, 0, -1 };
int d_col[] = { 1, 0, -1, 0 };

void water_bfs() {
    const int INF = 1e9;
    water_time.assign(R, vector<int>(C, INF));

    queue<pair<int, int>> q = water; 
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if (water_time[r][c] == 0) continue;
        water_time[r][c] = 0;
        water.push({ r,c });
    }
    // 실제 BFS
    queue<pair<int, int>> wq;
    while (!water.empty()) { wq.push(water.front()); water.pop(); }
    while (!wq.empty()) {
        auto [r, c] = wq.front(); wq.pop();
        for (int k = 0; k < 4; ++k) {
            int nr = r + d_row[k], nc = c + d_col[k];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (graph[nr][nc] == 'X' || graph[nr][nc] == 'D') continue;
            if (water_time[nr][nc] > water_time[r][c] + 1) {
                water_time[nr][nc] = water_time[r][c] + 1;
                wq.push({ nr, nc });
            }
        }
    }
}

void bfs(int start_r, int start_c, int end_r, int end_c) {
    queue<pair<int, int>> q;
    q.push({ start_r, start_c });
    dist[start_r][start_c] = 0;

    while (!q.empty()) {
        auto [now_r, now_c] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int next_r = now_r + d_row[i];
            int next_c = now_c + d_col[i];
            if (0 > next_r || next_r >= R || 0 > next_c || next_c >= C) continue;

            if (graph[next_r][next_c] == 'D') {
                std::cout << dist[now_r][now_c] + 1 << endl;
                return;
            }

            if (graph[next_r][next_c] == '.' && dist[next_r][next_c] == -1) {
                int nt = dist[now_r][now_c] + 1;
                if (nt < water_time[next_r][next_c]) {
                    dist[next_r][next_c] = nt;
                    q.push({ next_r, next_c });
                }
            }
        }
    }

    std::cout << "KAKTUS" << endl;
    return;
}

int main(void) {
    cin.tie(0); std::cout.tie(0); ios::sync_with_stdio(false);
    cin >> R >> C;
    graph.assign(R, vector<char>(C, '.'));
    dist.assign(R, vector<int>(C, -1));

    int start_r = -1, start_c = -1;
    int end_r = -1, end_c = -1;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> graph[r][c];
            if (graph[r][c] == 'S') {
                graph[r][c] = '.';
                start_r = r; start_c = c;
            }
            if (graph[r][c] == 'D')
                end_r = r, end_c = c;
            if (graph[r][c] == '*')
                water.push({ r, c });
        }
    }

    // 물 도착 시각 전처리
    water_bfs();
    bfs(start_r, start_c, end_r, end_c);
}
