#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	int donate;
	if (N >= 1'000'000) donate = N * 0.2;
	else if (N >= 500'000) donate = N * 0.15;
	else if (N >= 100'000) donate = N  * 0.1;
	else donate = N * 0.05;

	cout << donate << " " << N - donate;
}