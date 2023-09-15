/**
 * @problem: P8536 「Wdoi-2」幻胧月睨
 * @link: https://www.luogu.com.cn/problem/P8536
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
#define int long long

#define ONLINE_JUDGE

using i64 = long long;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std::cin >> n;
  std::string str; std::cin >> str;
  int cnt = 0;
  for (auto ch : str) if (ch == '0') ++cnt;
  int cnt2 = cnt;
  for (auto ch : str) {
    if (ch == '1') std::cout << ++cnt << " ";
    else std::cout << cnt2-- << " ";
  }
  std::cout << "\n";
}

bool rt = true;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  // freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}


