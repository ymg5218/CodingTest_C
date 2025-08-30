// 17179

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N, M, L;
vector<int> cut_point;
vector<int> cnt;

int solution(int goal_cnt) {
	int left = 0;
	int right = L;
	while (left <= right) {
		int mid = (left + right) / 2;
		int prev = 0; int cut_count = 0;
		for (int i = 1; i <= M + 1; i++) {
			if (cut_point[i] - prev >= mid) {
				cut_count++;
				prev = cut_point[i];
			}
		}

		if (cut_count > goal_cnt) 
			left = mid + 1;
		else 
			right = mid - 1;
		
	}
	return right;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N >> M >> L;
	cnt.assign(N, 0);
	cut_point.assign(M + 2, 0);
	for (int i = 1; i <= M; i++) {
		cin >> cut_point[i];
	}
	cut_point[M + 1] = L;

	for (int i = 0; i < N; i++) {
		cin >> cnt[i];
		cout << solution(cnt[i]) << endl;;
	}
	

}