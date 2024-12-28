// 10158
#include<iostream>

using namespace std;

int main() {
    int w, h, x, y, t;
    cin >> w >> h >> x >> y >> t;
    int xt = t;
    int yt = t;
    int resultX, resultY;

    if (xt - (w - x) < 0) {
        resultX = x + xt;
    }
    else {
        xt -= w - x;
        if ((xt / w) % 2 == 0) {
            resultX = w - (xt % w);
        }
        else {
            resultX = xt % w;
        }
    }
    if (yt - (h - y) < 0) {
        resultY = y + yt;
    }
    else {
        yt -= h - y;
        if ((yt / h) % 2 == 0) {
            resultY = h - (yt % h);
        }
        else {
            resultY = yt % h;
        }
    }


    cout << resultX << " " << resultY;


}