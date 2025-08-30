#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> maps) {
<<<<<<< HEAD
    int d_row[] = {0, 1, 0, -1};
=======
    int d_row[] = { 0, 1, 0, -1 };
>>>>>>> dca016cacaf980c44063ad3079e0a02f665da7a4
    int d_col[] = { 1, 0, -1, 0 };

    int r_cnt = maps.size();
    int c_cnt = maps[0].size();
    vector<vector<int>> dis(r_cnt, vector<int>(c_cnt, -1));

    int now_row = 0, now_col = 0;
    dis[now_row][now_col] = 1;
    queue<pair<int, int>> q;
    q.push({ now_row, now_col });
<<<<<<< HEAD
    
    while (!q.empty()) {
        auto [now_row, now_col] = q.front();
        q.pop();
        
=======

    while (!q.empty()) {
        auto [now_row, now_col] = q.front();
        q.pop();

>>>>>>> dca016cacaf980c44063ad3079e0a02f665da7a4
        for (int i = 0; i < 4; i++) {
            int next_row = now_row + d_row[i];
            int next_col = now_col + d_col[i];
            if (next_row < 0 || next_col < 0 || next_row >= r_cnt || next_col >= c_cnt ||
                dis[next_row][next_col] != -1 || maps[next_row][next_col] == 0)
<<<<<<< HEAD
                continue; 
=======
                continue;
>>>>>>> dca016cacaf980c44063ad3079e0a02f665da7a4
            dis[next_row][next_col] = dis[now_row][now_col] + 1;
            if (next_row == r_cnt - 1 && next_col == c_cnt - 1)
                break;
            q.push({ next_row, next_col });
        }
    }
    return dis[r_cnt - 1][c_cnt - 1];
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    answer = bfs(maps);

    return answer;
}

int main(void) {
    vector<vector<int>> maps{ {1,0,1,1,1} ,{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} };
    cout << solution(maps);
}