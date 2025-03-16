// 15650

#include <iostream>
#include <vector>
using namespace std;

int N;
int M;

void backtracking(int idx, bool used[], int usedCnt, vector<int> usedList) {
	if (usedCnt == M) {
		for (int i = 0; i < M; i++) {
			cout << usedList[i] << " ";
		}
		cout << "\n"; return;
	}
	for (; idx < N; idx++) {
		if (!used[idx]) {
			usedList.push_back(idx + 1);used[idx] = true;
			backtracking(idx, used, usedCnt + 1, usedList);
			usedList.pop_back(); used[idx] = false;
		}
	}
}

int main(void) {
	cin >> N >> M;
	
	bool* used = new bool[N] {false};
	vector<int> usedList;
	backtracking(0, used, 0, usedList);
}