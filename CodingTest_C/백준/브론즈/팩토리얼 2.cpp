// 27433

#include <iostream>

using namespace std;

int main(void)
{
    int N;
    long long result = 1;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        result *= i;
    }
    cout << result;
}