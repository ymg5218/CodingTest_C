// 5670

#include <iostream>
#include <string>
#include <map>
#include <vector>

#define endl "\n"

using namespace std;

class trie {
private:
	bool fin = false;
	map<char, trie*> child;

public:
	void insert(string str) {
		trie* now = this;
		for (char c : str) {
			if (now->child[c] == nullptr) {
				now->child[c] = new trie();
			}
			now = now->child[c];
		}
		now->fin = true;
	}

	int auto_complete(string str) {
		int cnt = 1;
		trie* now = child[str[0]];
		for (int i = 1; i < str.size(); i++) {
			if (now->fin || now->child.size() > 1)
				cnt++;
			now = now->child[str[i]];
		}
		return cnt;
	}
};

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		trie* root = new trie();
		vector<string> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			root->insert(arr[i]);
		}

		int sum = 0;
		for (string str : arr) {
			sum += root->auto_complete(str);
		}
		double result = (double)sum / n;
		cout << fixed;
		cout.precision(2);
		cout << result << endl;
	}
}