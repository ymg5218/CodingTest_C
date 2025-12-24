// 5397

#include <iostream>
#include <list>
#define endl "\n"
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		list<char> L;
		list<char>::iterator cursor = L.begin();
		string s; cin >> s;
		for (char& c : s) {
			if (c == '<') {
				if (cursor != L.begin()) cursor--;
			}
			else if (c == '>') {
				if (cursor != L.end()) cursor++;
			}
			else if (c == '-') {
				if (cursor != L.begin()) {
					cursor = L.erase(prev(cursor));
				}
			}
			else {
				cursor = L.insert(cursor, c);
				cursor++;
			}
		}
		for (char& c : L)
			cout << c;
		cout << endl;
	}
}
