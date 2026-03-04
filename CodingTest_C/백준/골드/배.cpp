#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int N, M;
    cin >> N;
    vector<int> crane(N);
    for (int i = 0; i < N; i++) cin >> crane[i];

    cin >> M;
    vector<int> box(M);
    for (int i = 0; i < M; i++) cin >> box[i];

    sort(crane.rbegin(), crane.rend());
    sort(box.rbegin(), box.rend());

    if (box[0] > crane[0]) {
        cout << -1 << endl;
        return 0;
    }

    vector<bool> moved(M, false);
    vector<int> position(N, 0);
    int count = 0;
    int moved_boxes = 0;

    while (moved_boxes < M) {
        count++;
        for (int i = 0; i < N; i++) {
            while (position[i] < M) {
                if (!moved[position[i]] && crane[i] >= box[position[i]]) {
                    moved[position[i]] = true;
                    position[i]++;
                    moved_boxes++;
                    break;
                }
                position[i]++;
            }
        }
    }

    cout << count << endl;
    return 0;
}