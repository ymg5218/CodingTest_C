// 9250

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#define endl "\n"

using namespace std;

struct Trie {
	Trie* go[26];	// 현재 노드에서 해당 문자를 받으면 가는 노드
	Trie* fail;		// 현재 노드에서 해당 문자의 go 목적지가 없을 때 가는 노드
	bool output;	// 현재 노드에 도달하면 찾는 문자열 집합

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

		go[next]->insert(key.substr(1, key.size() - 1));	// 맨 앞 문자는 제외하고 전달한다.
	}
};

int N, Q;
Trie* root = new Trie;

void init() { // 입력 받기 및 failure 생성
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		root->insert(s); // 트라이에 S의 원소들을 모두 INSERT
	}

	queue<Trie*> q;		// 트라이 노드를 방문하며 fail 함수를 만든다.
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		Trie* current = q.front();
		q.pop();

		for (int i = 0; i < 26; i++) {	// 26개의 input 각각에 대해 처리
			Trie* next = current->go[i];
			if (!next)
				continue;

			if (current == root) // root의 fail은 root이다.
				next->fail = root;
			else {
				Trie* dest = current->fail;

				while (dest != root && !dest->go[i])		// fail을 참조할 가장 가까운 조상을 찾아간다.
					dest = dest->fail;

				if (dest->go[i])							// fail(px) = go(fail(p), x)
					dest = dest->go[i];

				next->fail = dest;
			}

			if (next->fail->output)							// fail(x) = y일 때, output(y) ⊂ output(x)
				next->output = true;

			q.push(next);									// 큐에 다음 노드 push
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

			while (current != root && !current->go[next])	// 현재 노드에서 갈 수 없으면 fail을 따라감
				current = current->fail;

			if (current->go[next])							// go 함수가 존재하면 이동. 루트면 이게 false일 수도 있다.
				current = current->go[next];

			if (current->output) {							// 현재 노드에 output 있으면 찾은 것이다.
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