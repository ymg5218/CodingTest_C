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
        int* visited = new int[20001] {0, };  // �湮 ���ο� ������ ����
        vector<int>* graph = new vector<int>[20001];
        queue<int> q;
        int u, v;
        cin >> V >> E;

        // �׷��� �Է�
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool result = true;  // ��� ����
        // ��� ������ ���� �˻�
        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0) {  // ���� �湮���� ���� ������ ���� BFS ����
                q.push(i);
                visited[i] = 1;  // ó�� ������ �� �� 1(RED)

                while (!q.empty()) {
                    int now_v = q.front();
                    q.pop();

                    // ���� ���� �ݴ� ������ �̿� ���� �� ����
                    for (int j = 0; j < graph[now_v].size(); j++) {
                        int next_v = graph[now_v][j];
                        if (visited[next_v] == 0) {  // ���� �湮���� ���� ����
                            visited[next_v] = (visited[now_v] == 1) ? 2 : 1;  // �� ����
                            q.push(next_v);
                        }
                        else if (visited[now_v] == visited[next_v]) {  // ���� ������ �̺� �׷��� �ƴ�
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
