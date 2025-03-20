// 1707

#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'

using namespace std;

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    int K, V, E;
    cin >> K;

    while (K--) {
        int* visited = new int[20001] {0, };  // 방문 여부와 색깔을 저장
        vector<int>* graph = new vector<int>[20001];
        queue<int> q;
        int u, v;
        cin >> V >> E;

        // 그래프 입력
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool result = true;  // 결과 변수
        // 모든 정점에 대해 검사
        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0) {  // 아직 방문하지 않은 정점에 대해 BFS 시작
                q.push(i);
                visited[i] = 1;  // 처음 시작할 때 색 1(RED)

                while (!q.empty()) {
                    int now_v = q.front();
                    q.pop();

                    // 현재 색과 반대 색으로 이웃 정점 색 지정
                    for (int j = 0; j < graph[now_v].size(); j++) {
                        int next_v = graph[now_v][j];
                        if (visited[next_v] == 0) {  // 아직 방문하지 않은 정점
                            visited[next_v] = (visited[now_v] == 1) ? 2 : 1;  // 색 반전
                            q.push(next_v);
                        }
                        else if (visited[now_v] == visited[next_v]) {  // 색이 같으면 이분 그래프 아님
                            result = false;
                            break;
                        }
                    }

                    if (!result) break;
                }
            }

            if (!result) break;
        }

        if (result) cout << "YES" << endl;
        else cout << "NO" << endl;

        delete[] visited;
        delete[] graph;
    }

    return 0;
}
