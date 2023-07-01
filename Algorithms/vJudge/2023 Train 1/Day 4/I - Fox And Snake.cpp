/**
 * \link: https://codeforces.com/problemset/problem/510/A
 * \category: 模拟 画图
 * 
 * 
 * 
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int kN = 55;
char a[kN][kN];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i += 2) {
		for (int j = 1; j <= m; ++j) a[i][j] = '#';
	}
	int flag = 1;
	for (int i = 2; i <= n; i += 2) {
		if (flag) {
			for (int j = 1; j < m; ++j) a[i][j] = '.';
			a[i][m] = '#';
			flag = 0;
		} else {
			a[i][1] = '#';
			for (int j = 2; j <= m; ++j) a[i][j] = '.';
			flag = 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cout << a[i][j];
		cout << '\n';
	}
	return 0;
}