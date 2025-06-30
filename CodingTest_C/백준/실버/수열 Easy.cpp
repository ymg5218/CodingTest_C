// 23827

#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"
#define ll long long

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	ll sum = 0;

	vector<int> seq(N);

	for (int i = 0; i < N; i++) {
		int n;
		cin >> seq[i];
		sum += seq[i];
	}
	
	ll result = 0;
	for (int i = 0; i < N - 1; i++) {
		sum -= seq[i];
		result += sum * seq[i];
		result %= 1000000007;
	}
	result == 0 ? 1 : result;
	cout << result << endl;
}