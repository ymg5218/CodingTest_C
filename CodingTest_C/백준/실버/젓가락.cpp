// 24228

#include <iostream>
#include <vector>

using namespace std;

long long N, R;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> N >> R;
	cout << 2 * R + N - 1;
}