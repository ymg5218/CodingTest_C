#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#define endl "\n"
#define ll long long

using namespace std;

int T;
ll N, A, B;
vector<ll> prime;
vector<ll> divide;
map<ll, int> m;

void build_prime() {
    const int LIMIT = 100000;
    vector<bool> isPrime(LIMIT + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= LIMIT; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= LIMIT; j += i)
            isPrime[j] = false;
    }
    for (int i = 2; i <= LIMIT; i++)
        if (isPrime[i]) prime.push_back(i);
}

void init() {
    cin >> A >> B >> N;
}

void solution(int idx) {
    divide.clear();
    m.clear();

    ll x = N;
    for (auto p : prime) {
        if (1LL * p * p > x) break;
        if (x % p == 0) {
            m[p] = 1;
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) m[x] = 1;

    for (auto& kv : m)
        divide.push_back(kv.first);

    ll ans = 0;
    ll bit = 1LL << divide.size();

    for (ll mask = 1; mask < bit; mask++) {
        ll cnt = 0, mul = 1;

        for (int j = 0; j < (int)divide.size(); j++) {
            if (mask & (1LL << j)) {
                cnt++;
                if (mul > B) { mul = B + 1; break; }
                mul *= divide[j];
            }
        }

        ll aa = (A + mul - 1) / mul;
        ll bb = B / mul;
        if (aa > bb) continue;

        ll add = bb - aa + 1;
        if (cnt & 1) ans += add;
        else ans -= add;
    }

    ll total_count = (ll)B - (ll)A + 1LL;
    cout << "Case #" << idx << ": " << (total_count - ans) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    build_prime();

    cin >> T;
    for (int i = 1; i <= T; i++) {
        init();
        solution(i);
    }
}
