// 10868

#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"

using namespace std;

class SegmentTree {
private:
	vector<int> segtree;
	vector<int> nodeArr;
	int height;
	int size;

public:
	SegmentTree(int N) {
		this->height = ceil(log2(N));
		this->size = (1 << (height + 1));
		this->segtree.resize(size);
	}

	int init(int node, int start, int end) {
		if (start == end) {
			this->segtree[node] = nodeArr[start];
			return this->segtree[node];
		}

		int mid = (start + end) / 2;

		segtree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
		return segtree[node];
	}

	void setNodeArr(int value) {
		nodeArr.push_back(value);
	}

	int getMinimum(int node, int start, int end, int left, int right) {
		// case 1 : [start, end] �� �ڿ� [left, right]�� �ִ� ���,
		// ��ġ�� �ʱ� ������ Ž���� �� �̻� �� �ʿ䰡 ����.
		if (left > end || right < start) return 2e9;
		
		// case 2 : [start, end]�� [left, right]�� ����
		if (left <= start && end <= right) return segtree[node];

		// case 3, 4 : ���� �ڽİ� ������ �ڽ��� ��Ʈ�� �ϴ� Ʈ������ �ٽ� Ž��
		int mid = (start + end) / 2;
		return min(getMinimum(node * 2, start, mid, left, right), getMinimum(node * 2 + 1, mid + 1, end, left, right));
	}
};

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	SegmentTree segtree(N);
	for (int i{ 0 }; i < N; i++) {
		int value;
		cin >> value;
		segtree.setNodeArr(value);
	}
	
	segtree.init(1, 0, N - 1);

	while (M--) {
		int start, end;
		cin >> start >> end;
		cout << segtree.getMinimum(1, 0, N - 1, start - 1, end - 1) << endl;
	}
}