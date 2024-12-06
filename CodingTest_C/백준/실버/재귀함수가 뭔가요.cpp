// 17478

#include <iostream>
using namespace std;

void recursion_answer(int rec_cnt, int end_cnt) {
	string under_bar = "";
	for (int i = 0; i < rec_cnt; i++) {
		under_bar.append("____");
	}
	
	if (rec_cnt == end_cnt) {
		cout << under_bar << "\"재귀함수가 뭔가요?\"" << endl;
		cout << under_bar << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
		cout << under_bar << "라고 답변하였지." << endl;
		return;
	}

	
	cout << under_bar << "\"재귀함수가 뭔가요?\"" << endl;
	cout << under_bar << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
	cout << under_bar << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
	cout << under_bar << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
	recursion_answer(rec_cnt + 1, end_cnt);
	cout << under_bar << "라고 답변하였지." << endl;

	return;
	
}

int main(void) {
	int N;
	cin >> N;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
	recursion_answer(0, N);
}