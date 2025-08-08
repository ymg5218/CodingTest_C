#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int first[] = { 1, 2, 3, 4, 5 };
    int second[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int third[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    auto [f_cnt, s_cnt, t_cnt] = make_tuple(0, 0, 0);

    for (int i = 0; i < answers.size(); i++) {
        if (first[i % 5] == answers[i]) f_cnt++;
        if (second[i % 8] == answers[i]) s_cnt++;
        if (third[i % 10] == answers[i]) t_cnt++;
    }

    int max_cnt = max(f_cnt, s_cnt);
    max_cnt = max(max_cnt, t_cnt);

    if (max_cnt == f_cnt) answer.push_back(1);
    if (max_cnt == s_cnt) answer.push_back(2);
    if (max_cnt == t_cnt) answer.push_back(3);

    return answer;
}

int main(void) {
    vector<int> answers = { 1, 3, 2, 4, 2 };
    auto res = solution(answers);
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
}