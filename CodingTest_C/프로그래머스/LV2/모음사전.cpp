#include <iostream>
#include <vector>
#include <string>

using namespace std;

int now_rank;
int target_rank;
<<<<<<< HEAD
vector<char> c{ 'A', 'E', 'I','O', 'U'};
=======
vector<char> c{ 'A', 'E', 'I','O', 'U' };
>>>>>>> dca016cacaf980c44063ad3079e0a02f665da7a4

void dfs(string now_word, string target) {
	now_rank++;

	if (now_word == target) {
		target_rank = now_rank;
		return;
	}

	if (now_word.size() >= 5) return;

<<<<<<< HEAD
	for (int i = 0; i < 5; i++) 
		dfs(now_word + c[i], target);
	
=======
	for (int i = 0; i < 5; i++)
		dfs(now_word + c[i], target);

>>>>>>> dca016cacaf980c44063ad3079e0a02f665da7a4
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