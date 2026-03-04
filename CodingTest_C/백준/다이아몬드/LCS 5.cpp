// 18438

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//	A string의 시작, 끝 인덱스 [a_start, a_end) , B string의 시작, 끝 인덱스 [b_start, b_end)
vector<int> Alg_B(int a_start, int a_end, int b_start, int b_end, const string& A, const string& B) {
	vector<int> K0, K1;
	int n = b_end - b_start;
	K1.resize(n + 1, 0);
	for (int i = a_start; i < a_end; i++) {
		K0 = K1;
		for (int j = 1; j <= n; j++) {
			if (A[i] == B[b_start + j - 1]) K1[j] = K0[j - 1] + 1;
			else K1[j] = max(K1[j - 1], K0[j]);
		}
	}
	return K1;
}

vector<int> Alg_B_rev(int a_start, int a_end, int b_start, int b_end, const string& A, const string& B) {
	vector<int> K0, K1;
	int n = b_end - b_start;
	K1.resize(n + 1, 0);
	for (int i = a_end - 1; i >= a_start; i--) {
		K0 = K1;
		for (int j = 1; j <= n; j++) {
			if (A[i] == B[b_end - j]) K1[j] = K0[j - 1] + 1;
			else K1[j] = max(K1[j - 1], K0[j]);
		}
	}
	return K1;
}

string lcs_result = "";

void Alg_C(int a_start, int a_end, int b_start, int b_end, const string& A, const string& B) {
	int m = a_end - a_start, n = b_end - b_start;
	if (a_start >= a_end) return;
	if (a_end - a_start == 1) {
		for (int i = b_start; i < b_end; i++) {
			if (A[a_start] == B[i]) {
				lcs_result += A[a_start];
				break;
			}
		}
		return;
	}
	int mid = (a_start + a_end) / 2;
	// 앞부분
	auto L = Alg_B(a_start, mid, b_start, b_end, A, B);

	// 뒷부분
	auto L_star = Alg_B_rev(mid, a_end, b_start, b_end, A, B);

	int max_val = -1, idx = 0;
	for (int j = 0; j <= n; j++) {
		if (L[j] + L_star[n - j] > max_val) {
			max_val = L[j] + L_star[n - j];
			idx = b_start + j;
		}
	}

	Alg_C(a_start, mid, b_start, idx, A, B);
	Alg_C(mid, a_end, idx, b_end, A, B);
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	string A, B;
	cin >> A >> B;
	
	if (A.size() > B.size()) swap(A, B);
	Alg_C(0, A.size(), 0, B.size(), A, B);

	cout << lcs_result.size() << "\n";
	for (auto r : lcs_result) {
		cout << r;
	}
}