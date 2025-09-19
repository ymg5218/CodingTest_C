// 20547

/*
	1. �Էµ����� �Ľ� -> ��� ���� �ð� ��, �ǹ� �� �̵� �ð��� �� ������ ����
	2. �� �ǹ��� ������ �ִ� ��θ� ��� -> �÷��̵� ����
	3. ���ǰ� ���� ���� ���۵Ǵ� �ǹ��� ��������, ���ǰ� ���۵Ǵ� �ð� ������� �ǹ����� �湮�ϸ� �ð��� ����. �ǹ� �� ������ �ð��� �������� ��.
	4. ���˿� �°� ���
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <numeric>
#define endl "\n"
#define INF 1'000'000'000

using namespace std;

int N, M;
string S;
string T;
vector<string> lec;
unordered_map<string, int> lectoi;
vector<pair<pair<int, int>, string>> lectime;
vector<vector<pair<int, int>>> fw;
vector<vector<int>> dp;

bool compare(const pair<pair<int, int>, string>& x, const pair<pair<int, int>, string>& y) {
	if (x.first.first != y.first.first) return x.first.first < y.first.first;
	if (x.second != y.second) return x.second < y.second;
	return x.first.second < y.first.second;
}

void init() {
	cin >> N >> M;
	lec.resize(N);
	lectime.resize(N);
	fw.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> S;
		lec[i] = S;
		lectoi[S] = i;

		cin >> T;
		int hh = stoi(T.substr(0, 2));
		int mm = stoi(T.substr(3, 2));
		lectime[i].first.first = 60 * hh + mm;

		cin >> T;
		hh = stoi(T.substr(0, 2));
		mm = stoi(T.substr(3, 2));
		lectime[i].first.second = 60 * hh + mm;
		lectime[i].second = S;
		if (lectime[i].first.second < lectime[i].first.first)
			lectime[i].first.second += 60 * 24;
	}

	sort(lectime.begin(), lectime.end(), compare);

	for (int i = 0; i < M; i++) {
		cin >> S;
		int v = lectoi[S];
		cin >> S;
		int u = lectoi[S];
		cin >> T;
		int hh = stoi(T.substr(0, 2));
		int mm = stoi(T.substr(3, 2));
		fw[v].push_back({ u, 60 * hh + mm });
		fw[u].push_back({ v, 60 * hh + mm });
	}
}

void floyd_warshall() {
	dp.resize(N, vector<int>(N, INF));

	for (int i = 0; i < N; i++) {
		dp[i][i] = 0;
		for (const auto& v : fw[i]) {
			auto [u, t] = v;
			dp[i][u] = min(dp[i][u], t);
			dp[u][i] = min(dp[u][i], t);
		}
	}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			if (dp[i][k] < INF)
				for (int j = 0; j < N; j++)
					if (dp[k][j] < INF)
						dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}

void solution() {
	// ���� �¼�(���� ����): ���� ���� ���۽ð� + ������
	int base_b = lectoi[lectime[0].second];
	int base_t = lectime[0].first.first;

	vector<int> ord(N);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int a, int b) {
		const auto& A = lectime[a], & B = lectime[b];
		if (A.first.second != B.first.second) return A.first.second < B.first.second;
		if (A.first.first != B.first.first) return A.first.first < B.first.first;
		return A.second < B.second;
		});

	vector<int> best(N, -INF);
	int answer = 0;

	for (int ii = 0; ii < N; ++ii) {
		int i = ord[ii];
		int bi = lectoi[lectime[i].second];
		int si = lectime[i].first.first;
		int ei = lectime[i].first.second;

		if (dp[base_b][bi] < INF) {
			int arrive = base_t + dp[base_b][bi];
			if (arrive <= ei) {
				int start_listen = max(si, arrive);
				best[i] = max(best[i], ei - start_listen);
			}
		}

		for (int jj = 0; jj < ii; ++jj) {
			int j = ord[jj];
			if (best[j] < 0) continue;

			int bj = lectoi[lectime[j].second];
			if (dp[bj][bi] >= INF) continue;

			int arrive = lectime[j].first.second + dp[bj][bi];
			if (arrive > ei) continue;

			int start_listen = max(si, arrive);
			best[i] = max(best[i], best[j] + (ei - start_listen));
		}

		answer = max(answer, best[i]);
	}

	int hh = answer / 60, mm = answer % 60;
	if (hh < 10) cout << '0'; cout << hh << ':';
	if (mm < 10) cout << '0'; cout << mm << '\n';
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	init();

	floyd_warshall();

	solution();
}