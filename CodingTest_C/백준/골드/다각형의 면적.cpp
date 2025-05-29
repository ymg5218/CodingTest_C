#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> pts(N);
    double cx = 0, cy = 0;

    // 점 입력 및 무게중심 계산용 합
    for (int i = 0; i < N; ++i) {
        cin >> pts[i].first >> pts[i].second;
        cx += pts[i].first;
        cy += pts[i].second;
    }

    cx /= N;
    cy /= N;

    double area = 0;

    // 삼각형 분해 (i, i+1, 기준점)
    for (int i = 0; i < N; ++i) {
        int j = (i + 1) % N;
        double x1 = pts[i].first, y1 = pts[i].second;
        double x2 = pts[j].first, y2 = pts[j].second;

        // 벡터 외적 기반으로 삼각형 넓이 계산
        double triangle_area = ((x1 - cx) * (y2 - cy) - (x2 - cx) * (y1 - cy)) / 2.0;
        area += triangle_area;
    }

    cout << fixed << setprecision(1) << abs(area) << endl;
    return 0;
}
