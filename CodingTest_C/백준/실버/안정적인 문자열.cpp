// 4889

#include <iostream>
#include <vector>
#include <string>

#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false)
#define endl "\n"

using namespace std;

int solution(string S){
	int cnt = 0;
	vector<char> stack;
	for (char s : S) {
		if (stack.empty()) {
			if (s == '{') stack.push_back(s);
			else {
				stack.push_back('{');
				cnt++;
			}
		}
		else if (stack.back() == '{') {
			if (s == '}') stack.pop_back();
			else stack.push_back(s);
		}
	}

	if (!stack.empty())
		cnt += stack.size() / 2;

	return cnt;
}

int main() {
	FASTIO;
	int seq = 1;
	while (1) {
		string S; cin >> S;
		if (S[0] == '-')
			break;
		cout << seq << ". " << solution(S) << endl;
		seq++;
	}
}