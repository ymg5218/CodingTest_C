// 4195

#include <iostream>
#include <unordered_map>
#include <vector>
#define endl "\n"

using namespace std;

class Kruscal {
private:
	int parent[200000];
	int size[200000];
	int people_cnt;

public:
	Kruscal() {
		for (int i{ 0 }; i < 200000; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	void set_people_cnt(int cnt) {
		this->people_cnt = cnt;
	}

	int find_parent(int a) {
		if (parent[a] == a) return a;
		return parent[a] = find_parent(parent[a]);
	}

	void union_find(int a, int b) {
		a = find_parent(a);
		b = find_parent(b);
		if (a != b) {
			if (a > b) {
				parent[a] = b; size[b] += size[a];
			}
			else {
				parent[b] = a; size[a] += size[b];
			}
		}
		
	}

	int solution(int a, int b) {
		int cnt = 0;

		union_find(a, b);

		return size[find_parent(a)];
	}
	
};

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	int T;
	int F;
	string f1, f2;
	unordered_map<string, int> people;

	cin >> T;
	for (int i{ 0 }; i < T; i++) {
		people.clear();
		Kruscal* k = new Kruscal();
		cin >> F;
		int seq = 0;
		for (int j{ 0 }; j < F; j++) {
			cin >> f1 >> f2;
			if (people.find(f1) == people.end()) people[f1] = seq; seq++;
			if (people.find(f2) == people.end()) people[f2] = seq; seq++;
			k->set_people_cnt(seq);
			cout << k->solution(people[f1], people[f2]) << endl;
		}
		
		delete k;
	}
}