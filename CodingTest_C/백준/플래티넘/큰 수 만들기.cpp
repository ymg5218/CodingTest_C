// 16496

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
vector<string> numbers;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution() {
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    for (int i = 0; i < N; i++) {
        if (answer == "" && numbers[i] == "0") {
            answer = "0";
            break;
        }
        answer += numbers[i];
    }

    return answer;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    cout << solution() << endl;
}