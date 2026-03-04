// 9251

#include <iostream>
#include <vector>

using namespace std;

int Alg_B(string A, string B) {
	vector<int> K0, K1;
	K1.resize(B.size() + 1, 0);
	for (int i = 0; i < A.size(); i++) {
		K0 = K1;
		for (int j = 1; j <= B.size(); j++) {
			if (A[i] == B[j - 1]) K1[j] = K0[j - 1] + 1;
			else K1[j] = max(K1[j - 1], K0[j]);
		}
	}
	return K1[B.size()];
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	string A, B;
	cin >> A >> B;

	cout << Alg_B(A, B);
}