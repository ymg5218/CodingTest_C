// 1094

#include <iostream>
#include <bitset>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int n;
	cin >> n;

	cout << bitset<8>(n).count() << endl;
}