// 10610

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define endl "\n"

using namespace std;

int main(void) {
	string n;
	cin >> n;
	
	sort(n.rbegin(), n.rend());
	
	int sum = 0;
	for (int i = 0; i < n.size(); i++) {
		sum += int(n[i]) - int('0');
	}
	
	if (sum % 3 != 0 || n[n.size() - 1] != '0') cout << -1;
	else {
		for (const auto& c : n) {
			cout << c << "";
		}
	}
	
}