// 6012

#include <iostream>
#include <vector>
#define endl "\n"
#define ll long long

using namespace std;

int N;
ll sum = 0;

void recursion(int s, int e) {
	if (e - s == 1) {
		sum += (s * e);
		return;
	}
	
	if (s == e)
		return;
	int mid = (s + e) / 2;
	recursion(s, mid);
	recursion(mid + 1, e);
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	
	recursion(1, N);
	
	cout << sum << endl;
}