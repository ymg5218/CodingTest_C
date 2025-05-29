// 13711

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define endl "\n"

using namespace std;

vector<int> arr1;
vector<int> arr2;
vector<int> lcs;

void LCS(int N) {
	arr2.resize(N);
	
	unordered_map<int, int> arr1_idx;
	for (int idx = 0; idx < N; idx++) {
		int n;
		cin >> n;
		arr1_idx[n] = idx;
	}
	
	for (int idx = 0; idx < N; idx++) {
		int n;
		cin >> n;
		arr2[idx] = arr1_idx[n];
	}
	int lcs_size = 0;
	for (int i = 0; i < N; i++) {
		int now = arr2[i];
		if (lcs_size == 0 || lcs[lcs_size - 1] < now) {
			lcs.push_back(now);
			lcs_size++;
		}

		else {
			int left = 0;
			int right = lcs_size - 1;
			while (left < right) {
				int mid = (left + right) / 2;
				if (lcs[mid] > now) {
					right = mid;
				}
				else {
					left = mid + 1;
				}
			}
			lcs[left] = now;
		}
	}
	
	cout << lcs_size << endl;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int N;
	cin >> N;
	LCS(N);
}