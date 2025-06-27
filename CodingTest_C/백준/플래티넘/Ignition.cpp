// 13141

#include <vector>
#include <iostream>
using namespace std;

const int INF = 987654321;
int vertex_num, edge_num;
vector<vector<int>> adj;  //���� �������� �̾��� ��츸 ����
vector<vector<int>> dist; //�÷��̵�� ����� �ִ� ��θ� ����

double BurnGraph() {
    double shortest_time = INF, longest_time, spent_time, remain_len;
    int edge_len;

    for (int start = 1; start <= vertex_num; ++start) {
        //start �������� �¿��� �� ������ ������ ������� �ð��� ����
        longest_time = 0;

        for (int from = 1; from <= vertex_num; ++from) {
            for (int to = 1; to <= vertex_num; ++to) {
                edge_len = adj[from][to];

                if (edge_len != -1) { //from ������ �������� ������� ���� ���
                    remain_len = edge_len - (dist[start][to] - dist[start][from]);

                    //remain_len�� 0�����̸� �̹� ��ź ��츦 �ǹ�
                    if (remain_len > 0) {
                        spent_time = (remain_len / 2) + dist[start][to];
                        longest_time = max(spent_time, longest_time);
                    }

                }

            }
        }
        //� �������� �¿��� ���� ���� ��� �׷����� �¿� �� �ִ��� ����
        shortest_time = min(longest_time, shortest_time);
    }
    return shortest_time;
}

void Floyd() {
    for (int k = 1; k <= vertex_num; ++k)
        for (int i = 1; i <= vertex_num; ++i)
            for (int j = 1; j <= vertex_num; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> vertex_num >> edge_num;
    adj = vector<vector<int>>(vertex_num + 1, vector<int>(vertex_num + 1, -1));
    dist = vector<vector<int>>(vertex_num + 1, vector<int>(vertex_num + 1, INF));

    for (int i = 1; i <= vertex_num; ++i)
        dist[i][i] = 0;

    int S, E, L;
    for (int i = 0; i < edge_num; ++i) {
        cin >> S >> E >> L;
        if (adj[S][E] == -1 || adj[S][E] < L) {
            adj[S][E] = L;
            adj[E][S] = L;
        }
        if (dist[S][E] == INF || L < dist[S][E]) {
            dist[S][E] = L;
            dist[E][S] = L;
        }
    }

    Floyd();
    cout << fixed;
    cout.precision(1);
    cout << BurnGraph() << endl;
    return 0;
}