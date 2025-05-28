// 33924

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int bowl[4][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 0} };
	int N, M, K;
	cin >> N >> M >> K;
	bowl[N - 1][M - 1] = 1;
	string command;
	cin >> command;
	for (auto& c : command) {
		int temp;
		switch (c) {
			case 'A':
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						swap(bowl[i][j], bowl[i + 2][j]);
					}
				}
				continue;
			case 'B':
				swap(bowl[0][0], bowl[1][1]);
				swap(bowl[2][0], bowl[3][1]);

				swap(bowl[0][1], bowl[1][0]);
				swap(bowl[2][1], bowl[3][0]);
				continue;

			case 'C':
				swap(bowl[0][0], bowl[3][1]);
				swap(bowl[0][1], bowl[3][0]);

				swap(bowl[1][0], bowl[2][1]);
				swap(bowl[2][0], bowl[1][1]);
				continue;

			case 'D':
				temp = bowl[3][1];
				bowl[3][1] = bowl[2][1];
				bowl[2][1] = bowl[1][1];
				bowl[1][1] = bowl[0][1];
				bowl[0][1] = bowl[0][0];
				bowl[0][0] = bowl[1][0];
				bowl[1][0] = bowl[2][0];
				bowl[2][0] = bowl[3][0];
				bowl[3][0] = temp;
				continue;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (bowl[i][j] == 1) {
				cout << i + 1 << " " << j + 1 << endl;
				break;
			}
		}
	}
}