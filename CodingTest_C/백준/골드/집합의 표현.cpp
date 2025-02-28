#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
	vector<int> parent;
	
public:
	UnionFind(int n) {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
		}
	}

	int findParent(int x) {
		if (parent[x] == x) return x;
		return parent[x] = findParent(parent[x]);
	}

	void unionParent(int x, int y) {
		x = findParent(x);
		y = findParent(y);

		if (x <= y) parent[y] = x;
		else parent[x] = y;
	}

	bool isConnected(int x, int y) {
		if (findParent(x) == findParent(y)) return true;
		return false;
	}
};

int main(void) {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);
	cout.tie(nullptr);
	int n, m;
	int op, a, b;

	cin >> n >> m;
	UnionFind uf(n);
	
	for (int i = 0; i < m; i++) {
		cin >> op >> a >> b;

		if (op == 0) {
			uf.unionParent(a, b);
		}
		else {
			if (uf.isConnected(a, b)) cout << "YES";
			else cout << "NO";
			cout << "\n";
		}
	}
}