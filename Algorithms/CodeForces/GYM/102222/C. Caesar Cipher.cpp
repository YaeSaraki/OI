/**
 * https://codeforces.com/gym/102222/problem/C
 * \category: 凯撒密i码 字符串
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int rod = 1;

void inline solve() {
	int n, m; cin >> n >> m;
	string str1, str2; cin >> str1 >> str2;
	
	int temp = 0;
//cout << str1[0] << " " << str2[0] << endl;
	temp = str2[0] - str1[0];
//	else temp = (26 - (str2[0] - str1[0])), cout << temp << endl;
	string str3; cin >> str3;
	for (auto &it : str3) it = ((it - temp) - 'A' + 26) % 26 + 'A'; // ! it - temp 可为负数， 需要 + 26 再 MOD
	cout << "Case #" << rod++ << ": " << str3 << '\n';
	return ;
}

bool rt = true;
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
	if (rt) { int T; cin >> T; while (T--) solve() ;}
	else solve();
	return 0;
}