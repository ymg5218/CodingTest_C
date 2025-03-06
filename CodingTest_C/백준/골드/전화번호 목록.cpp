// 5052

#include <iostream>
using namespace std;

struct Trie {
	bool finished = false;
	bool isChild = false;
	// 0 ~ 9
	Trie* number[10];
	
	Trie() {
		for (int i = 0; i < 10; i++) number[i] = NULL;
	}
	
	~Trie() {
		for (int i = 0; i < 10; i++) if (number[i]) delete number[i];
	}

	bool insert(const char* s) {
		if (*s == '\0') {
			finished = true;
			if (isChild) return false;
			return true;
		}
		int curr = *s - '0';
		if (finished == true) return false;
		if (!number[curr]) {
			number[curr] = new Trie();
		}
		isChild = true;
		if (!finished && number[curr]->insert(s + 1)) return true;
		else return false;
	}
};

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int T;
	int N;
	string number;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		Trie *root = new Trie();

		int seq;
		bool isFinished = false;


		for (seq = 0; seq < N; seq++) {
			cin >> number;
			if (!isFinished) {
				if (root->insert(number.c_str()) == false) isFinished = true;
			}
			
		}
		if (!isFinished) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		
		delete root;
	}
}