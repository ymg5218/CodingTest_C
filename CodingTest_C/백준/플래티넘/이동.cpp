// 1067

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#define endl "\n"
#define ll long long

using namespace std;
typedef complex<double> base;

const double PI = acos(-1);

int N;
vector<ll> a, b;

void FFT(vector<base>& a, bool inv) {
	int n = a.size();
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for (; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if (i < j) swap(a[i], a[j]);
	}


	for (int i = 1; i < n; i <<= 1) {
		double angle = (inv ? -1 : 1) * PI / i;
		base w = { cos(angle), sin(angle) };
		
		for (int j = 0; j < n; j += i << 1) {
			base th = { 1, 0 };
			for (int k = 0; k < i; k++) {
				base tmp = a[i + j + k] * th;
				a[i + j + k] = a[j + k] - tmp;
				a[j + k] += tmp;
				th *= w;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < n; i++) {
			a[i] /= n;
		}
	}
}

vector<ll> multiply(vector<ll>& a, vector <ll>& b) {
	vector<base> A(a.begin(), a.end()), B(b.begin(), b.end());

	int n = 1;
	while (n < A.size() + B.size()) n <<= 1;

	A.resize(n); FFT(A, false);
	B.resize(n); FFT(B, false);
	
	for (int i = 0; i < n; i++)
		A[i] *= B[i];
	FFT(A, true);

	vector<ll> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = (ll)round(A[i].real());
	}
	return res;
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	a.assign(N * 2, 0), b.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		a[i + N] = a[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
	reverse(b.begin(), b.end());
	vector<ll> res = multiply(a, b);

	ll answer = 0;
	for (ll v : res)
		answer = max(answer, v);
	cout << answer << endl;
}