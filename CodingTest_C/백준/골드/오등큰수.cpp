// 17299

#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#define endl "\n"
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)

using namespace std;

int N;

vector<tuple<int, int, int>> stk; // {값, 그 값의 개수, 인덱스}
vector<int> arr;
vector<int> new_arr;
vector<int> result;

int main() {
	FASTIO;

	cin >> N;
	result.resize(N, -1);
	arr.resize(N, 0);
	new_arr.resize(N, 0);
	
	unordered_map<int, int> um;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		
		if (um.find(arr[i]) == um.end())
			um[arr[i]] = 1;
		else
			um[arr[i]]++;
	}
	
	for (int i = 0; i < N; i++) {	// 3 3 2 1 1 2 3
		new_arr[i] = um[arr[i]];
	}

	for (int i = 0; i < N; i++) {
		int now_val = arr[i];
		int now_val_cnt = new_arr[i];
		while (!stk.empty() && get<1>(stk.back()) < now_val_cnt) {
			auto [val, val_cnt, idx] = stk.back();
			stk.pop_back();
			result[idx] = now_val;
		}
		stk.push_back({now_val, now_val_cnt, i});
	}

	for (const auto& res : result) {
		cout << res << " ";
	}
}
