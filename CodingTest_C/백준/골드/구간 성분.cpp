// 10840

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ull unsigned long long

using namespace std;

string str1, str2;
int str1_len, str2_len;
ull p = 1234567891;
vector<ull> alpha_hash(26);

int find(int len) {
	ull str2_H = 0;
	vector<int> str2_cnt(26, 0);
	vector<ull> v; // M의 길이 len짜리 구간들의 해시값을 담는 벡터

	for (int i = 0; i < str2_len - len + 1; i++) {
		if (i == 0) {
			for (int j = i; j < i + len; j++) {
				str2_cnt[str2[j] - 'a']++;
			}
			for (int j = 0; j < 26; j++) {
				str2_H += str2_cnt[j] * alpha_hash[j];
			}
		}
		v.push_back((str2_H));
		
		if (i != str2_len - len) {
			str2_H -= alpha_hash[str2[i] - 'a'];
			str2_cnt[str2[i] - 'a']--;
			str2_cnt[str2[i + len] - 'a']++;
			str2_H += alpha_hash[str2[i + len] - 'a'];
		}
	}

	sort(v.begin(), v.end());

	ull str1_H = 0;
	vector<ull> str1_cnt(26, 0);

	for (int i = 0; i < str1_len - len + 1; i++) {
		if (i == 0) {
			for (int j = i; j < i + len; j++) {
				str1_cnt[str1[j] - 'a']++;
			}
			for (int j = 0; j < 26; j++) {
				str1_H += str1_cnt[j] * alpha_hash[j];
			}
		}
		if (binary_search(v.begin(), v.end(), str1_H))
			return 1;

		if (i != str1_len - len) {
			str1_H -= alpha_hash[str1[i] - 'a'];
			str1_cnt[str1[i] - 'a']--;
			str1_cnt[str1[i + len] - 'a']++;
			str1_H += alpha_hash[str1[i + len] - 'a'];
		}
	}
	return 0;
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> str1 >> str2;
	
	ull x = 1;
	for (int i = 0; i < 25; i++) {
		alpha_hash[i] = x;
		x *= 1501;
		x %= p;
	}

	if (str1.length() > str2.length())
		swap(str1, str2);

	str1_len = str1.length();
	str2_len = str2.length();
	for (int len = str1_len; len > 0; len--) {
		if (find(len)) {
			cout << len << endl;
			return 0;
		}
	}
	cout << 0;
}