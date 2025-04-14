// 14570

#include <iostream>
#include <vector>
#define endl "\n"
#define ll long long
using namespace std;


struct Node {
	int idx;
	Node* left;
	Node* right;
};

class Solution {
private:
	vector<int> leaf_priority;
	vector<Node*> tree;
	int N;
	ll int K;
	int leaf_cnt = 0;
	Node* root;

public:
	Solution(int N) {
		root = new Node(1);
		tree.resize(N + 1);
		this->N = N;
	}

	void setK(ll int K) {
		this->K = K;
	}

	void setLeafPrioritySize() {
		leaf_priority.resize(this->leaf_cnt);
	}

	void setLeafPriority() {

	}

	void setTree(int idx, int left, int right) {
		Node* n = new Node(idx);
		if (left == -1) n->left = nullptr;
		else {
			Node* child_left = new Node(left);
			n->left = child_left;
		}
		if (right == -1) n->right = nullptr;
		else {
			Node* child_right = new Node(right);
			n->right = child_right;
		}
		if (left == -1 && right == -1) this->leaf_cnt++;
	}



};

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N;
	cin >> N;
	Solution sln(N);
	
	for (int i{ 1 }; i <= N; i++) {
		int left, right;
		cin >> left >> right;
		sln.setTree(i, left, right);
	}
	sln.setLeafPrioritySize();

	ll int K;
	cin >> K;
	sln.setK(K);


	
}