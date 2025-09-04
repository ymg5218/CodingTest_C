// 17179

#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int N, M, L;
vector<int> cut_point;
vector<int> cnt;

int solution(int goal_cnt) {
	int left = 1;
	int right = L;
	int ans = right;
	while (left <= right) {
		int mid = (left + right) / 2;
		int prev = 0; int cut_count = 0;
		for (int i = 1; i <= M + 1; i++) {
			// 마지막으로 커팅하고 생기는 조각이 mid보다 작은 경우까지 고려
			if (cut_point[i] - prev >= mid && L - cut_point[i] >= mid) {
				cut_count++;
				prev = cut_point[i];
			}
		}

		if (cut_count >= goal_cnt) {
			ans = mid;
			left = mid + 1;
		}
		else 
			right = mid - 1;
	}
	return ans;
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