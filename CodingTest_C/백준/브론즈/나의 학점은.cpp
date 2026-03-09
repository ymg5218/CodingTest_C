// 17826

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> score(50);

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	for (int i = 0; i < 50; i++) {
		cin >> score[i];
	}
	sort(score.rbegin(), score.rend());

	int my_score; cin >> my_score;
	
	for (int i = 0; i < 50; i++) {
		if (score[i] == my_score) {
			if (0 <= i && i < 5) {
				cout << "A+";
			}
			else if (5 <= i && i < 15) {
				cout << "A0";
			}
			else if (15 <= i && i < 30) {
				cout << "B+";
			}
			else if (30 <= i && i < 35) {
				cout << "B0";
			}
			else if (35 <= i && i < 45) {
				cout << "C+";
			}
			else if (45 <= i && i < 48) {
				cout << "C0";
			}
			else
				cout << "F";
			break;
		}
	}
}