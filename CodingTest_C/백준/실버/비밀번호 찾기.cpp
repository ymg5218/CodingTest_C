// 17219

#include <iostream>
#include <unordered_map>
#define endl "\n"
using namespace std;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N, M;
	string site, pw;
	unordered_map<string, string> map;

	cin >> N >> M;

	while (N--) {
		cin >> site >> pw;
		map[site] = pw;
	}
	
	while (M--) {
		cin >> site;
		cout << map[site] << endl;
	}
	
}