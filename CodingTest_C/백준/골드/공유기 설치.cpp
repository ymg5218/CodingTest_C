// 2110

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
vector<int> arr;;

int binary_search() {
	int installed_router;

	int left = 0; // 첫 번째 집 ~ 첫 번째 집 거리
	int right = arr[N - 1] - arr[0]; // 첫 번째 집 ~ 마지막 집 거리
	int mid; // 적절한 간격 찾기
	
	int result; // 해답이 되는 값

	int start; // 첫 번째 집 위치
	int now; // 간격을 확인할 집 위치

	while (left <= right) {
		int installed_router = 1; // 첫 번째 집은 설치하고 시작

		mid = (left + right) / 2;

		start = arr[0];

		// 각 공유기 간격 확인
		for (int i = 0; i < N; i++) {
			now = arr[i];

			// 집 간격이 현재 기준인 mid 거리를 넘는지 확인한 뒤, 넘는 간격에는 공유기를 설치하고 해당 위치를 다시 탐색 시작 위치로 변경
			if (now - start >= mid) {
				installed_router++;
				start = now;
			}
		}

		if (installed_router >= C) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return result;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	cin >> N >> C;
	
	int h;
	for (int i = 0; i < N; i++) {
		cin >> h;
		arr.push_back(h);
	}

	sort(arr.begin(), arr.end());

	cout << binary_search();

}