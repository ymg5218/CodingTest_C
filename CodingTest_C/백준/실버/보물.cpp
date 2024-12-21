// 1026

#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int N;
	cin >> N;

	int* Aarr = new int[N];
	int* Barr = new int[N];
	int result = 0;

	for (int i = 0; i < N; i++) {
		cin >> Aarr[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> Barr[i];
	}

	sort(Aarr, Aarr + N);
	sort(Barr, Barr + N, desc);

	for (int idx = 0; idx < N; idx++) {
		result += (Aarr[idx] * Barr[idx]);
	}
	cout << result << '\n';
}