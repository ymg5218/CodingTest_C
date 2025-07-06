// 17386, 17387

#include <iostream>
#define ll long long
using namespace std;

int ccw(auto a, auto b, auto c) {
    auto [ax, ay] = a;
    auto [bx, by] = b;
    auto [cx, cy] = c;

    ll ans = 0;
    ans += (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);

    if (ans > 0)
        return 1;
    if (ans == 0)
        return 0;
    if (ans < 0)
        return -1;
}

int main(void) {
    ll p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, p4_x, p4_y;

    cin >> p1_x >> p1_y >> p2_x >> p2_y >> p3_x >> p3_y >> p4_x >> p4_y;
    pair<ll, ll> p1 = make_pair(p1_x, p1_y);
    pair<ll, ll> p2 = make_pair(p2_x, p2_y);
    pair<ll, ll> p3 = make_pair(p3_x, p3_y);
    pair<ll, ll> p4 = make_pair(p4_x, p4_y);
    int L1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int L2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (L1 == 0 && L2 == 0) {
        if (p1 > p2)
            swap(p1, p2);
        if (p3 > p4)
            swap(p3, p4);
        if (p1 <= p4 && p2 >= p3)
            cout << 1;
        else
            cout << 0;
        return 0;
    }
    else {
        if (L1 <= 0 && L2 <= 0)
            cout << 1;
        else
            cout << 0;
    }
}