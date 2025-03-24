// 7785

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#define endl "\n"

using namespace std;

bool compare(string a, string b) {
	return a > b;
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int n;
	string name, log;

	unordered_map<string, bool> list;
	vector<string> result;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> log;
		if (log == "enter") {
			if (list.find(name) == list.end()) list[name] = true;
		}
		else {
			if (list.find(name) != list.end()) list.erase(name);
		}
	}

	for (auto& person : list) {
		result.push_back(person.first);
	}

	sort(result.rbegin(), result.rend());

	for (auto& person : result) {
		cout << person << endl;
	}
}