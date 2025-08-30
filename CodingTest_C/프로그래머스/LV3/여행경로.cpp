#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


int used_cnt = 0;
bool finished = false;

void dfs(string now_city, vector<vector<string>> tickets, vector<string>& answer, vector<bool>& used) {
    if (used_cnt == tickets.size()) {
        finished = true;
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (finished)
            return;

        string origin = tickets[i][0];
        string dest = tickets[i][1];
        if (origin == now_city && !used[i]) {
            used[i] = true;
            used_cnt++;
            answer.push_back(dest);
            dfs(dest, tickets, answer, used);
            if (finished)
                return;
<<<<<<< HEAD
            
=======

>>>>>>> dca016cacaf980c44063ad3079e0a02f665da7a4
            used[i] = false;
            used_cnt--;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    answer.push_back("ICN");
    sort(tickets.begin(), tickets.end());
<<<<<<< HEAD
    vector<bool> used(tickets.size(), false);  
=======
    vector<bool> used(tickets.size(), false);
>>>>>>> dca016cacaf980c44063ad3079e0a02f665da7a4

    dfs("ICN", tickets, answer, used);

    return answer;
}

int main(void) {
    vector<vector<string>> tickets = { {"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} };
    auto result = solution(tickets);
    for (const auto& r : result) {
        cout << r << " ";
    }
}