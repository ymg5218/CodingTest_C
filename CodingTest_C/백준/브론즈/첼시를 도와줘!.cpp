// 11098

#include <iostream>
#define endl "\n"

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) {
		int p;
		cin >> p;
		int max_price = -1;
		string max_name = "";
		
		while(p--) {
			string name;
			int price;
			cin >> price >> name;
			if (price > max_price) {
				max_price = price;
				max_name = name;
			}
		}
		cout << max_name << endl;
	}
}