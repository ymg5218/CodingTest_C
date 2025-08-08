#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int backtracking(int k, vector<vector<int>> dungeons, vector<bool> visited, int cnt) {
	int max_cnt = cnt;
	for (int i = 0; i < dungeons.size(); i++) {
		auto now = dungeons[i];
		int min_req = now[0]; // 최소 요구 피로도
		int exh = now[1]; // 소모 피로도
		if (k >= min_req && !visited[i]) {
			visited[i] = true;
			max_cnt = max(max_cnt, backtracking(k - exh, dungeons, visited, cnt + 1));
			visited[i] = false;
		}
			
	}
	return max_cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
	vector<bool> visited(dungeons.size(), false);
	return backtracking(k, dungeons, visited, 0);
}

int main(void) {
	int k = 80;
	vector<vector<int>> dungeons = { {80, 20}, {50, 40}, {30, 10} };
	cout << solution(k, dungeons) << endl;
}
