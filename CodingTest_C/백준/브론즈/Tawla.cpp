// 11800

#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int T;
int a, b;

vector<string> alias = {"Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
vector<string> double_alias = {"Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"};

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> T;
	int case_num = 1;
	while (case_num <= T) {
		cin >> a >> b;
		if (a < b) swap(a, b);

		if (a == 6 && b == 5) {
			cout << "Case " << case_num << ": " << "Sheesh Beesh" << endl;
		}
		else if (a == b) cout << "Case " << case_num << ": " << double_alias[a - 1] << endl;
		else cout << "Case " << case_num << ": " << alias[a - 1] << " " << alias[b - 1] << endl;

		case_num++;
	}
}
