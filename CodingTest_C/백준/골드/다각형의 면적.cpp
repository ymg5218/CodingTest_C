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

    // �� �Է� �� �����߽� ���� ��
    for (int i = 0; i < N; ++i) {
        cin >> pts[i].first >> pts[i].second;
        cx += pts[i].first;
        cy += pts[i].second;
    }

    cx /= N;
    cy /= N;

    double area = 0;

    // �ﰢ�� ���� (i, i+1, ������)
    for (int i = 0; i < N; ++i) {
        int j = (i + 1) % N;
        double x1 = pts[i].first, y1 = pts[i].second;
        double x2 = pts[j].first, y2 = pts[j].second;

        // ���� ���� ������� �ﰢ�� ���� ���
        double triangle_area = ((x1 - cx) * (y2 - cy) - (x2 - cx) * (y1 - cy)) / 2.0;
        area += triangle_area;
    }

    cout << fixed << setprecision(1) << abs(area) << endl;
    return 0;
}
