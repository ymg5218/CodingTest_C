#include<iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int star_cnt;
	int gap_cnt;
	string row;
	for (int i = 0; i < N; i++) {
		gap_cnt = i;
		star_cnt = 2 * (N - i - 1) + 1;
		
		// 왼쪽 공백 채우기
		for (int g = 0; g < gap_cnt; g++) {
			row.append(" ");
		}

		for (int s = 0; s < star_cnt; s++) {
			row.append("*");
		}

		cout << row << endl;

		row = "";
	}
}