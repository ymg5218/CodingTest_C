// 17478

#include <iostream>
using namespace std;

void recursion_answer(int rec_cnt, int end_cnt) {
	string under_bar = "";
	for (int i = 0; i < rec_cnt; i++) {
		under_bar.append("____");
	}
	
	if (rec_cnt == end_cnt) {
		cout << under_bar << "\"����Լ��� ������?\"" << endl;
		cout << under_bar << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
		cout << under_bar << "��� �亯�Ͽ���." << endl;
		return;
	}

	
	cout << under_bar << "\"����Լ��� ������?\"" << endl;
	cout << under_bar << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
	cout << under_bar << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
	cout << under_bar << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
	recursion_answer(rec_cnt + 1, end_cnt);
	cout << under_bar << "��� �亯�Ͽ���." << endl;

	return;
	
}

int main(void) {
	int N;
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
	recursion_answer(0, N);
}