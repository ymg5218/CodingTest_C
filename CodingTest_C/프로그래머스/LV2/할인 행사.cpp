#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#define endl "\n"

using namespace std;

bool checkSale(vector<int> number) {
	for (int i = 0; i < number.size(); i++) {
		if (number[i] != 0) return false;
	}
	return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;

	unordered_map<string, int> item_index;
	for (int i = 0; i < want.size(); i++) {
		item_index[want[i]] = i;
	}
	for (int i = 0; i < 10; i++) {
		string now_item = discount[i];
		if (item_index.find(now_item) != item_index.end()) {
			number[item_index[now_item]]--;
		}
	}
	if (checkSale(number)) answer++;

	for (int i = 1; i <= discount.size() - 10; i++) {
		string delete_item = discount[i - 1];
		string add_item = discount[i + 9];
		if (item_index.find(delete_item) != item_index.end()) {
			number[item_index[delete_item]]++;
		}
		if (item_index.find(add_item) != item_index.end()) {
			number[item_index[add_item]]--;
		}
		if (checkSale(number)) answer++;
	}

	return answer;
}

int main(void) {
	vector<string> want = { "banana", "apple", "rice", "pork", "pot" };
	vector<int> number = { 3, 2, 2, 2, 1 };
	vector<string> discount = {
		"chicken", "apple", "apple", "banana", "rice", "apple",
		"pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"
	};

	cout << solution(want, number, discount) << endl;
}