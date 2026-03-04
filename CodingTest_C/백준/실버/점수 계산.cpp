// 2822

#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

using namespace std;

vector<pair<int, int>> score(8);

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	for (int i = 0; i < 8; i++) {
		cin >> score[i].first;
		score[i].second = i + 1;
	}
	
	sort(score.rbegin(), score.rend());

	int sum = 0;
	vector<int> prob_num(5);
	for (int i = 0; i < 5; i++) {
		sum += score[i].first;
		prob_num[i] = score[i].second;
	}
	cout << sum << endl;
	
	sort(prob_num.begin(), prob_num.end());

	for (int i = 0; i < 5; i++) {
		cout << prob_num[i] << " ";
	}
}