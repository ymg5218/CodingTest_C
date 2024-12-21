#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	long long N;
	cin >> N;

	vector<int> result;
	long long result_length = 0;
	
	while (N > 1) {
		result.push_back(N % 2);
		result_length++;
		N /= 2;
	}
	if (N == 1) cout << 1;
	for (int i = result_length - 1; i >= 0; i--) {
		cout << result[i];
	}
}