#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

struct job {
	int arr_time;
	int req_time;
	int num;
	bool operator < (const job& j1) const {
		if (arr_time != j1.arr_time) return arr_time < j1.arr_time;
		if (req_time != j1.req_time) return req_time < j1.req_time;
		return num < j1.num;
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	for (int i = 0; i < jobs.size(); i++) {
		jobs[i].push_back(i);
	}
	sort(jobs.begin(), jobs.end());

	priority_queue<job, vector<job>> pq;
	int now_arrt = jobs[0][0];
	int now_reqt = jobs[0][1];
	int now_num = jobs[0][2];
	
	int i = 1;
	int now_endtime = now_arrt + now_reqt; // 현재 작업이 끝날 시간
	answer += now_reqt;
	while (i <= jobs.size()) {
		if (i < jobs.size() && now_endtime >= jobs[i][0]) {
			pq.push({ jobs[i][0], jobs[i][1], jobs[i][2] });
		}
		else {
			if (i < jobs.size()) {
				while (now_endtime < jobs[i][0]) {
					
				}
			}
		}
		i++;
	}

	return answer;
}

int main(void) {
	vector<vector<int>> jobs = { {0, 3}, {1, 9}, {3, 5} };
	cout << solution(jobs) << "\n";
}