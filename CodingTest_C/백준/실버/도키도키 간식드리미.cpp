// 12789

#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> get_snack;
	vector<int> wait;
	
	bool is_valid = true;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (is_valid) {
			if (x == 1) {
				get_snack.push_back(x);
				if (!wait.empty() && wait.back() == get_snack.back() + 1) {
					while (!wait.empty()) {
						if (wait.back() != get_snack.back() + 1) {
							break;
						}
						get_snack.push_back(wait.back());
						wait.pop_back();
					}
				}
			}
			else {
				if (!get_snack.empty() && get_snack.back() == x - 1) {
					get_snack.push_back(x);
					if (!wait.empty() && wait.back() == get_snack.back() + 1) {
						while (!wait.empty()) {
							if (wait.back() != get_snack.back() + 1) {
								break;
							}
							get_snack.push_back(wait.back());
							wait.pop_back();
						}
					}
				}
				else {
					if (wait.empty() || wait.back() > x)
						wait.push_back(x);
					else
						is_valid = false;
				}
			}
		}
	}
	if (is_valid) cout << "Nice";
	else cout << "Sad";
}