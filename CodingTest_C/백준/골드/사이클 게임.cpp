// 20040

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> parent;

int find(int a)
{
	if (parent[a] == a)
		return a;

	return parent[a] = find(parent[a]);
}

bool Parent(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		return false;
	return true;
}

void Union(int a, int b)
{
	a = find(parent[a]);
	b = find(parent[b]);

	if (a != b)
	{
		if (a >= b)
			parent[a] = b;
		else
			parent[b] = a;
	}
}


int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> n >> m;
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (Parent(a, b))
		{
			cout << i + 1;
			return 0;
		}
		Union(a, b);
	}
	cout << "0";
}