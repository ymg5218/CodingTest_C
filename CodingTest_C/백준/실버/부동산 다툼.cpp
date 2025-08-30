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
    occupancy[1] = true; // 루트 노드(1번)는 항상 점유 중

    while (Q--) {
        int goto_land;
        cin >> goto_land;

        int idx = goto_land;
        vector<int> path;

        // 바텀-업 역추적: 루트까지 경로 추적
        while (idx >= 1) {
            path.push_back(idx);
            idx /= 2;
        }

        bool is_blocking = false;

        // 루트 제외한 경로를 역순 탐색 (중간에 점유당한 땅 있는지 확인)
        for (int i = (int)path.size() - 2; i >= 0; i--) {
            if (occupancy[path[i]]) {
                cout << path[i] << "\n";
                is_blocking = true;
                break;
            }
        }

        if (!is_blocking) {
            cout << 0 << "\n";
            occupancy[goto_land] = true; // 원하는 땅 점유 성공
        }
    }

    return 0;
}
