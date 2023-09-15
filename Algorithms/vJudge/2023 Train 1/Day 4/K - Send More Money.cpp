/**
 * https://vjudge.csgrandeur.cn/problem/AtCoder-abc198_d
 * \category: 暴力 数字
 * 
 * 
 * 
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#define F(i) for (int i = 0; i <= 9; ++i)
#define int long long
using namespace std;

char chs[127];
int wow[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

signed main() {
	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	int cnt = 0;
	int a, b, c, d, e, f, g, h, i, j;
	
	for (int i = 0; i < s1.size(); ++i) {
		char chi = s1[i];
		if (!chs[chi]) {
			chs[chi] = 'a' + cnt;
			++cnt;
		}
	}
	for (int i = 0; i < s2.size(); ++i) {
		char chi = s2[i];
		if (!chs[chi]) {
			chs[chi] = 'a' + cnt;
			++cnt;
		}
	}
	for (int i = 0; i < s3.size(); ++i) {
		char chi = s3[i];
		if (!chs[chi]) {
			chs[chi] = 'a' + cnt;
			++cnt;
		} 
	}
//	for (int i = 'a'; i <= 'z'; ++i) cout << chs[i] << ' ';

	do {
//		a = wow[0], b = wow[1], c = wow[2], d = wow[3], e = wow[4], f = wow[5], g = wow[6], h = wow[7], i = wow[8], j = wow[9];
		if (wow[chs[s1[0]] - 'a'] == 0 || wow[chs[s2[0]] - 'a'] == 0 || wow[chs[s3[0]] - 'a'] == 0) continue;
//		for (int i = 0; i < 10; ++i) cout << wow[i];
//		cout << " " << wow[chs[s1[0]] - 'a'] << ' ';
		int ss1 = 0; 
			for (int i = 0; i < s1.size(); ++i){
				ss1 = wow[chs[s1[i]] - 'a'] + ss1 * 10;
			} 
		int ss2 = 0;
			for (int i = 0; i < s2.size(); ++i){
				ss2 = wow[chs[s2[i]] - 'a'] + ss2 * 10;
			} 	
		int ss3 = 0;
			for (int i = 0; i < s3.size(); ++i){
				ss3 = wow[chs[s3[i]] - 'a'] + ss3 * 10;
			}
		if (ss1 + ss2 == ss3) return cout << ss1 << '\n' << ss2 << '\n' << ss3 << '\n', 0;
	}	while (next_permutation(wow, wow + 10));
	
	return cout << "UNSOLVABLE\n", 0;

//	for (int i = 0; i < s2.size(); ++i) chs[s2[i] - '0'] = 1;
//	for (int i = 0; i < s3.size(); ++i) chs[s3[i] - '0'] = 1;
//	for (int i = 0; i < 26; ++i) {
//		if (chs[i]) {
//
//		}
//	}
}