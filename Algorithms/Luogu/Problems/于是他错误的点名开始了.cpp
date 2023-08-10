/**
 * @problem: P2580 于是他错误的点名开始了
 * @link: https://www.luogu.com.cn/problem/P2580
 * @category: 字典🌲 trie
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = long long;
using PI = std::pair<int, int>;

const int kN = 5e5 + 233;
int cnt = 0;
auto exist = std::vector<int>(kN);
auto son = std::vector<std::vector<int> > (kN, std::vector<int>(26));

void Insert(std::string str) {
	int p = 0;
	for (int i = 0; i < str.length(); ++i) {
		int u = str[i] - 'a';
		if (!son[p][u]) son[p][u] = ++cnt;
		p = son[p][u];
	}
	++exist[p];
}

int Query(std::string str) {
	int p = 0;
	for (int i = 0; i < str.length(); ++i) {
		int u = str[i] - 'a';
		if (!son[p][u]) return 0;
		p = son[p][u];
	}
	/* 每次查询数量加一，用来统计点名次数 */
	return exist[p]++;
}

inline void solve() {
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::string str; std::cin >> str;
		Insert(str);
	}
	int m; std::cin >> m;
	for (int i = 0; i < m; ++i) {
		std::string str; std::cin >> str;
		int op = Query(str);
		if (op == 1)      std::cout << "OK\n";
		else if (op >= 2) std::cout << "REPEAT\n";
		else              std::cout << "WRONG\n";
	}
}

bool rt = false;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}


