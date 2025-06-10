#include <iostream>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, J, S, H, K;
    cin >> N >> J >> S >> H >> K;

    string h2, h1, h0;
    cin >> h2 >> h1 >> h0;

    vector<string> track(N);
    for (int i = 0; i < N; i++) {
        track[i] = string() + h2[i] + h1[i] + h0[i];
    }

    vector<bool> handled(N, false);

    // 1. "..^" (1�� ���� �켱)
    for (int i = 0; i < N; i++) {
        if (track[i] == "..^" && J > 0) {
            J--;
            handled[i] = true;
        }
    }

    // 2. "vv." (�����̵� �켱)
    for (int i = 0; i < N; i++) {
        if (!handled[i] && track[i] == "vv." && S > 0) {
            S--;
            handled[i] = true;
        }
    }

    // 3. ".^^" (2�� ����: ���� 2ȸ �ʿ�)
    for (int i = 0; i < N; i++) {
        if (!handled[i] && track[i] == ".^^" && J >= 2) {
            J -= 2;
            handled[i] = true;
        }
    }

    // 4. ���� ��ֹ��� ���ؼ��� ������
    for (int i = 0; i < N; i++) {
        if (!handled[i] && track[i] != "...") {
            H -= K;
            if (H <= 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << H << endl;
    return 0;
}
