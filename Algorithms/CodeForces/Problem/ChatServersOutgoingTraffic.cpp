/**
 * @problem: Chat Server's Outgoing Traffic
 * @link: https://codeforces.com/problemset/problem/5/A
 * @category: implementation*1000
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
  int ans =  0, cnt = 0;
  std::string str;
  while (getline(std::cin, str)) {
    if (str[0] == '+') ++cnt;
    else if (str[0] == '-') --cnt;
    else {
      auto it = std::find(ALL(str), ':');
      ans += (int)(str.end() - it - 1) * cnt;
    }
  }
  std::cout << ans << '\n';
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
