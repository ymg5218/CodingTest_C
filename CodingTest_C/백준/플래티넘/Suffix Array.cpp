// 9248

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl "\n"

using namespace std;

struct Compare {
	const vector<int>& bucket;
	int d;
	Compare(const vector<int>& _bucket, int _d) : bucket(_bucket), d(_d) {
	}
	bool operator() (int a, int b) {
		if (bucket[a] != bucket[b]) return bucket[a] < bucket[b];
		return bucket[a + d] < bucket[b + d];
	}
};

vector<int> getSA(const string& s) {
	int N = s.size();
	int d = 1;
	vector<int> bucket(N + 1);
	for (int i{ 0 }; i < N; i++) {
		bucket[i] = s[i];
	}
	bucket[N] = -1;

	vector<int> perm(N);
	for (int i{ 0 }; i < N; i++) {
		perm[i] = i;
	}
	
	while (true) {
		Compare compareUsing2d(bucket, d);
		sort(perm.begin(), perm.end(), compareUsing2d);

		d *= 2;
		if (d >= N) break;

		vector<int> bucket2d(N + 1);
		bucket2d[N] =  -1;
		bucket2d[perm[0]] = 0;
		for (int i{ 1 }; i < N; i++) {
			if (compareUsing2d(perm[i - 1], perm[i]))
				bucket2d[perm[i]] = bucket2d[perm[i - 1]] + 1;
			else
				bucket2d[perm[i]] = bucket2d[perm[i - 1]];
		}
		bucket = bucket2d;
	}
	return perm;
}

vector<int> getLCP(string& s, vector<int>& sa) {
	int N = s.size();
	vector<int> lcp(N, 0);
	vector<int> invSA(N, 0);

	for (int i{ 0 }; i < N; i++) {
		invSA[sa[i]] = i;
	}
	int k = 0;
	for (int i{ 0 }; i < N; i++) {
		if (invSA[i] == N - 1) {
			k = 0;
			continue;
		}
		int j = sa[invSA[i] + 1];

		while (i + k < N && j + k < N && s[i + k] == s[j + k]) k++;
		
		lcp[invSA[i]] = k;

		if (k > 0) k--;
	}
	return lcp;
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s;
	cin >> s;
	vector<int> sa = getSA(s);
	vector<int> lcp = getLCP(s, sa);
	for (int i{ 0 }; i < sa.size(); i++) {
		cout << sa[i] + 1 << " ";
	}
	cout << endl << "x " ;
	for (int i{ 0 }; i < lcp.size() - 1; i++) {
		cout << lcp[i] << " ";
	}
	cout << endl;
}