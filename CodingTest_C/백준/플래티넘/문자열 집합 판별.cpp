// 9250

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#define endl "\n"

using namespace std;

struct Trie {
	Trie* go[26];	// ���� ��忡�� �ش� ���ڸ� ������ ���� ���
	Trie* fail;		// ���� ��忡�� �ش� ������ go �������� ���� �� ���� ���
	bool output;	// ���� ��忡 �����ϸ� ã�� ���ڿ� ����

	Trie() {
		fill(go, go + 26, nullptr);
		output = false;
	}
	
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (go[i]) delete go[i];
		}
	}

	void insert(string key) {
		if (key == "\0") {
			output = true;
			return;
		}

		int next = key[0] - 'a';
		if (!go[next])
			go[next] = new Trie;

		go[next]->insert(key.substr(1, key.size() - 1));	// �� �� ���ڴ� �����ϰ� �����Ѵ�.
	}
};

int N, Q;
Trie* root = new Trie;

void init() { // �Է� �ޱ� �� failure ����
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		root->insert(s); // Ʈ���̿� S�� ���ҵ��� ��� INSERT
	}

	queue<Trie*> q;		// Ʈ���� ��带 �湮�ϸ� fail �Լ��� �����.
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		Trie* current = q.front();
		q.pop();

		for (int i = 0; i < 26; i++) {	// 26���� input ������ ���� ó��
			Trie* next = current->go[i];
			if (!next)
				continue;

			if (current == root) // root�� fail�� root�̴�.
				next->fail = root;
			else {
				Trie* dest = current->fail;

				while (dest != root && !dest->go[i])		// fail�� ������ ���� ����� ������ ã�ư���.
					dest = dest->fail;

				if (dest->go[i])							// fail(px) = go(fail(p), x)
					dest = dest->go[i];

				next->fail = dest;
			}

			if (next->fail->output)							// fail(x) = y�� ��, output(y) �� output(x)
				next->output = true;

			q.push(next);									// ť�� ���� ��� push
		}
	}
}

void aho_corasick() {
	cin >> Q;
	while (Q--) {
		string str;
		cin >> str;

		Trie* current = root;
		bool result = false;
		for (int idx = 0; str[idx]; idx++) {
			int next = str[idx] - 'a';

			while (current != root && !current->go[next])	// ���� ��忡�� �� �� ������ fail�� ����
				current = current->fail;

			if (current->go[next])							// go �Լ��� �����ϸ� �̵�. ��Ʈ�� �̰� false�� ���� �ִ�.
				current = current->go[next];

			if (current->output) {							// ���� ��忡 output ������ ã�� ���̴�.
				result = true;
				break;
			}
		}
		cout << (result ? "YES" : "NO") << endl;
	}
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	init();
	aho_corasick();
}