// 1269

#include <iostream>
#include <unordered_map>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	unordered_map<int, bool> A, B, result;
	int n, m;
	int num;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num;
		A[num] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		B[num] = true;
	}

	for (auto& A_num : A) {
		if (B.find(A_num.first) == B.end()) result[A_num.first] = true;
	}
	
	for (auto& B_num : B) {
		if (A.find(B_num.first) == A.end()) {
			if (result.find(B_num.first) == result.end()) result[B_num.first] = true;
		}
	}

	cout << result.size();
}