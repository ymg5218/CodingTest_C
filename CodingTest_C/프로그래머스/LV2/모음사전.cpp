#include <iostream>
#include <vector>
#include <string>

using namespace std;

int now_rank;
int target_rank;
vector<char> c{ 'A', 'E', 'I','O', 'U' };

void dfs(string now_word, string target) {
	now_rank++;

	if (now_word == target) {
		target_rank = now_rank;
		return;
	}

	if (now_word.size() >= 5) return;

	for (int i = 0; i < 5; i++)
		dfs(now_word + c[i], target);

}

int solution(string word) {
	now_rank = -1;
	dfs("", word);
	return target_rank;
}

int main(void) {
	string word = "AAAAE";
	cout << solution(word) << endl;
}