#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<bool> occupancy(N + 1, false);
    occupancy[0] = true;
    occupancy[1] = true; // ��Ʈ ���(1��)�� �׻� ���� ��

    while (Q--) {
        int goto_land;
        cin >> goto_land;

        int idx = goto_land;
        vector<int> path;

        // ����-�� ������: ��Ʈ���� ��� ����
        while (idx >= 1) {
            path.push_back(idx);
            idx /= 2;
        }

        bool is_blocking = false;

        // ��Ʈ ������ ��θ� ���� Ž�� (�߰��� �������� �� �ִ��� Ȯ��)
        for (int i = (int)path.size() - 2; i >= 0; i--) {
            if (occupancy[path[i]]) {
                cout << path[i] << "\n";
                is_blocking = true;
                break;
            }
        }

        if (!is_blocking) {
            cout << 0 << "\n";
            occupancy[goto_land] = true; // ���ϴ� �� ���� ����
        }
    }

    return 0;
}
