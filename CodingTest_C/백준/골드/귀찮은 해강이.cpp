// 24391

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parent;
vector<int> lesson_seq;

int get_parent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = get_parent(parent[x]);
}

void set_union(int x, int y) {
	if (x > y) swap(x, y);
	x = get_parent(x);
	y = get_parent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> M;
	parent.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		set_union(x, y);
	}

	lesson_seq.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> lesson_seq[i];
	}

	int res = 0;
	for (int i = 1; i < N; i++) {
		if (get_parent(lesson_seq[i]) != get_parent(lesson_seq[i - 1]))
			res++;
	}
	cout << res;
}