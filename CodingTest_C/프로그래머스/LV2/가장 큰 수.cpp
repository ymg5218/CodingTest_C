#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    int size = numbers.size();
    vector<string> nums(size);
    for (int i = 0; i < size; i++)
        nums[i] = to_string(numbers[i]);

    sort(nums.begin(), nums.end(), compare);

    for (int i = 0; i < size; i++) {
        if (answer == "" && nums[i] == "0") {
            answer = "0";
            break;
        }
        answer += nums[i];
    }

    return answer;
}

int main(void) {
    vector<int> numbers = { 6, 10, 2 };
    cout << solution(numbers) << endl;
}