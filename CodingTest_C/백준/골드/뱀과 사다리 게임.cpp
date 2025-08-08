#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"
#define INF 101

using namespace std;

vector<int> board(101, 0); // zero-idx : dummy. board[i] : i�� ĭ���� jump�� �� �ִ� ĭ 
vector<int> visited(101, INF); // zero-idx : dummy. visited[i] : 1�� ĭ���� ����Ͽ� �ּҷ� �ֻ����� ���� �������� ���� �ֻ��� ���� Ƚ��.

int N, M;

void solution() {
    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = now + i;
            if (next > 100) continue;
            if (board[next] > 0)
                next = board[next];
            if (visited[next] > visited[now] + 1) {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }
    cout << visited[100] << endl;
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    while (N--) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    while (M--) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    solution();

}