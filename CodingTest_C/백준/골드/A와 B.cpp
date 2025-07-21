// 12904

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S, T;
    cin >> S >> T;

    int s = 0;
    int e = T.length() - 1;
    bool isReverse = false;

    while (e - s + 1 != S.length()) {
        if (isReverse) {
            if (T[s] == 'B') {
                isReverse = false;
            }
            s++;
        }
        else {
            if (T[e] == 'B') {
                isReverse = true;
            }
            e--;
        }
    }

    bool matched = true;
    if (isReverse) {
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] != T[e - i]) {
                matched = false;
                break;
            }
        }
    }
    else {
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] != T[s + i]) {
                matched = false;
                break;
            }
        }
    }

    cout << (matched ? 1 : 0) << '\n';
    return 0;
}
