// 14425

#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(NULL);

	int N, M;
	cin >> N >> M;

	unordered_map<string, bool> dict;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		dict[s] = true;
	}
	int result = 0;
	for (int seq = 0; seq < M; seq++) {
		cin >> s;
		if (dict[s]) result++;
	}
	cout << result;
}