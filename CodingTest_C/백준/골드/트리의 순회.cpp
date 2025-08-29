// 2263

#include <iostream>
#include <vector>
#include <unordered_map>
#define endl "\n"

using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;
unordered_map<int, int> inorder_index;

void solution(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end)
		return;

	int root_index = inorder_index[postorder[post_end]];
	int left_size = root_index - in_start;
	int right_size = in_end - root_index;
	cout << inorder[root_index] << ' ';

	solution(in_start, root_index - 1,post_start, post_start + left_size - 1);
	solution(root_index + 1, in_end, post_start + left_size, post_end - 1);
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> n;
	inorder.assign(n, 0);
	postorder.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		inorder_index[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
	solution(0, n - 1, 0, n - 1);
}