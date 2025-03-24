// 9375

#include <iostream>
#include <unordered_map>
#define endl "\n";
using namespace std;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int T;
	int n;
	string cloth, type;
	
	unordered_map<string, int> clothes;

	cin >> T;
	for (int i = 0; i < T; i++) {
		clothes.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> cloth >> type;
			if (clothes.find(type) == clothes.end()) {
				clothes.insert(make_pair(type, 1));
			}
			else {
				clothes[type]++;
			}
		}

		int result = 1;
		for (const auto& pair : clothes) {
			result *= (pair.second + 1);
		}
		cout << result - 1 << endl;
	}

}