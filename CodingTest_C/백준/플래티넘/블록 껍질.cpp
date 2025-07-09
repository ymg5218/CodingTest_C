// 1708

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl "\n"
#define ll long long

using namespace std;

struct P {
	ll x, y;
	P(int x = 0, int y = 0) : x(x), y(y) {}
};

int N;
vector<P> points;
ll start_x, start_y = 40001;
P start;

ll CCW(const P& p1, const P& p2, const P& p3) {
	ll res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);

	if (res > 0) // 반시계
		return 1;
	else if (res < 0) // 시계
		return -1;
	else
		return 0;
}

bool angle_sort(P& p1, P& p2) {
	int cc = CCW(P(start_x, start_y), p1, p2);

	if (cc)					// 각도가 작은 순
		return cc > 0;
	else if (p1.y != p2.y)  // y가 작은 순
		return p1.y < p2.y;
	else					// x가 작은 순
		return p1.x < p2.x;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	
	points.resize(N);

	for (int i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;
		points[i] = P(x, y);
		if (start_y > y or (start_y == y && start_x > x)) {// 시작점 세팅
			start_y = y;
			start_x = x;
		}
	}
	
	start = { start_x, start_y };

	sort(points.begin(), points.end(), angle_sort);

	stack<P> stk;
	stk.push(points[0]);
	stk.push(points[1]);
	
	for (int i = 2; i < N; i++) {
		while (stk.size() >= 2) {
			P top_2 = stk.top();
			stk.pop();
			 
			P top_1 = stk.top();
			if (CCW(top_1, top_2, points[i]) > 0) {
				stk.push(top_2);
				break;
			}
		}
		stk.push(points[i]);
	}
	cout << stk.size() << endl;
	
}