// 25584

#include <iostream>
#include <unordered_map>

using namespace std;

int N;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	
	unordered_map<string, int> um;
	string name;

	for (int week = 0; week < N; week++) {					// 각 주마다
		for (int timeLine = 0; timeLine < 4; timeLine++) {	// 근무시간표 확인
			for (int day = 0; day < 7; day++)				// 각 요일마다
			{
				cin >> name;
				if (name == "-")
					continue;
				if (timeLine == 0) {				// 08:00 ~ 12:00 (4시간)
					if (um.find(name) == um.end()) {
						um.insert({ name, 4 });
					}
					else {
						um[name] += 4;
					}
				}
				else if (timeLine == 1) {			// 12:00 ~ 18:00 (6시간)
					if (um.find(name) == um.end()) {
						um.insert({ name, 6 });
					}
					else {
						um[name] += 6;
					}
				}
				else if (timeLine == 2) {			// 18:00 ~ 22:00 (4시간)
					if (um.find(name) == um.end()) {
						um.insert({ name, 4 });
					}
					else {
						um[name] += 4;
					}
				}
				else {								// 22:00 ~ 08:00 (10시간)	
					if (um.find(name) == um.end()) {
						um.insert({ name, 10 });
					}
					else {
						um[name] += 10;
					}
				}
			}
		}
	}

	int min_time = 1e9;
	int max_time = 0;

	for (auto& [_, time] : um) {
		if (min_time > time) {
			min_time = time;
		}
		if (max_time < time) {
			max_time = time;
		}
	}

	if (max_time - min_time > 12)
		cout << "No";
	else
		cout << "Yes";
}