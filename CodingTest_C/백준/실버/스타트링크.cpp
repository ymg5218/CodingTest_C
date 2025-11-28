// 5014

#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	
	vector<int> visited(F + 1, -1);
	queue<int> q;
	q.push(S);
	visited[S] = 0;
	while (!q.empty()) {
		int now_floor = q.front();
		q.pop();
		
		if (now_floor + U <= F && visited[now_floor + U] == -1) {
			visited[now_floor + U] = visited[now_floor] + 1;
			if (now_floor + U == G) break;
			q.push(now_floor + U);
		}
		
		if (now_floor - D >= 1 && visited[now_floor - D] == -1) {
			visited[now_floor - D] = visited[now_floor] + 1;
			if (now_floor + U == G) break;
			q.push(now_floor - D);
		}
	}
	if (visited[G] == -1) cout << "use the stairs" << endl;
	else cout << visited[G] << endl;
}