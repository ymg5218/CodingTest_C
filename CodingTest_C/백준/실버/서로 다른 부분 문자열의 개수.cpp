// 11478

#include <iostream>
#include <unordered_map>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	string s;
	unordered_map<string, bool> map;
	cin >> s;

	for (int start_idx{ 0 }; start_idx < s.size(); start_idx++) {
		string str = "";
		for (int end_idx{ start_idx }; end_idx < s.size(); end_idx++) {
			str += s[end_idx];
			if (!map[str]) {
				map[str] = true;
			}
		}
	}

	cout << map.size();
	
}