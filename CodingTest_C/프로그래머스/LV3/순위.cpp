#include <iostream>
#include <vector>
#include <string>
#define endl "\n"

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;


	vector<vector<int>> fw(n + 1, vector<int>(n + 1, 0));

	for (auto& r : results) {
		int A = r[0]; int B = r[1];
		fw[A][B] = 1; // A°¡ B¸¦ ÀÌ±è
		fw[B][A] = -1; // B°¡ AÇÑÅ× Áü
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			
			for (int k = 1; k <= n; k++) {
				if (fw[i][j] == 1 || fw[i][j] == -1) break;
				if (fw[i][k] == 1 && fw[k][j] == 1) {
					fw[i][j] = 1; fw[j][i] = -1;
				}
				else if (fw[i][k] == -1 && fw[k][j] == -1) {
					fw[i][j] = -1; fw[j][i] = 1;
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (fw[i][j] != 0) cnt++;
		}
		if (cnt == n - 1) answer++;
	}

	return answer;
}

int main(void) {
	int n = 5;
	vector<vector<int>> results = { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} };
	cout << solution(n, results) << endl;
}