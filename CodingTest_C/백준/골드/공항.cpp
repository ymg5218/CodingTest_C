// 10775

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int G, P;
vector<int> parent;

int get_parent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = get_parent(parent[x]);
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> G >> P;
	parent.assign(G + 1, 0);
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}
	
	int cnt = 0;
	for (int i = 0; i < P; i++) {
		int g;
		cin >> g;
		if (get_parent(g) == 0) {
			cout << cnt << endl;
			exit(0);
		}
			
		else {
			g = get_parent(g);
			parent[g] = parent[g - 1];
			cnt++;
		}
	}
	cout << cnt << endl;
	
}