/**
 * @problem: P1914 小书童——凯撒密码
 * @link: https://www.luogu.com.cn/problem/P1914
 * @category: string
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std:: cin >> n;
  std::string str; std::cin >> str;
  for (auto &it : str) it = char(((it - 'a') + n) % 26 + 'a');
  std::cout << str << '\n';
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
