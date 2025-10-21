// 10825

#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

struct Student {
	string name;
	int korean;
	int english;
	int math;
	bool operator<(const Student& s) const {
		if (korean != s.korean)
			return korean > s.korean;
		if (english != s.english)
			return english < s.english;
		if (math != s.math)
			return math > s.math;
		return name < s.name;
	}
};

int N;
vector<Student> list;

int main() {
	FASTIO;
	cin >> N;
	list.resize(N);
	for (int i = 0; i < N; i++) {
		Student tmp;
		cin >> tmp.name >> tmp.korean >> tmp.english >> tmp.math;
		list[i] = tmp;
	}
	sort(list.begin(), list.end());
	for (int i = 0; i < N; i++) {
		cout << list[i].name << endl;
	}
}