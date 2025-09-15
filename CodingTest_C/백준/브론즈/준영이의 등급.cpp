// 30008

#include <iostream>

using namespace std;

int N, K;

int get_grade(int rank) {
	int rate = rank * 100 / N;
	if (rate >= 0 && rate <= 4) return 1;
	if (rate > 4 && rate <= 11) return 2;
	if (rate > 11 && rate <= 23) return 3;
	if (rate > 23 && rate <= 40) return 4;
	if (rate > 40 && rate <= 60) return 5;
	if (rate > 60 && rate <= 77) return 6;
	if (rate > 77 && rate <= 89) return 7;
	if (rate > 89 && rate <= 96) return 8;
	else return 9;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int rank;
		cin >> rank;
		cout << get_grade(rank) << " ";
	}
}