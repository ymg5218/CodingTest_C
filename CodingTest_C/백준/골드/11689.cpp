#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	ll n;
	cin >> n;
	
	ll answer = n;
	
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			answer -= answer / i;
			
			while (n % i == 0) {
				n /= i;
			}
		}
	}

	if (n > 1) {
		answer -= answer / n;
	}
	cout << answer << endl;
}