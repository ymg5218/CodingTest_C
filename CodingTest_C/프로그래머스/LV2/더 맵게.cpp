#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	int cnt = scoville.size();

	for (auto& s : scoville) {
		pq.push(s);
	}

	while (pq.top() < K) {
		if (cnt <= 1)
			return -1;

		int min_1 = pq.top();
		pq.pop();
		int min_2 = pq.top();
		pq.pop();
		int new_s = min_1 + min_2 * 2;
		pq.push(new_s);
		cnt--;
		answer++;
	}

	return answer;
}

int main(void) {
	vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
	int K = 7;

	cout << solution(scoville, K) << endl;
}