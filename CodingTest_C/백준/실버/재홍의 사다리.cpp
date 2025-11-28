// 14842

#include <iostream>
#include <cmath>
#include <iomanip>
#define endl "\n"

using namespace std;

double W, H;
int N;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> W >> H >> N;
	double res;
	if (N % 2 == 0) {
		res = (double)(N - 2) / 4;
	}
	else {
		res = (double)(N - 1) * (N - 1) / (4 * N);
	}
	res *= 2.0 * H;
	cout << fixed << setprecision(6) << res << endl;
}