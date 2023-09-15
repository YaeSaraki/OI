/**
 * @problem: K. 音乐游戏
 * @link: https://codeforces.com/gym/103389/problem/K
 * @category: 
 * @date: 
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std::cin >> n;
  std::string str;
  int ans = 0;
  while (std::getline(std::cin, str)) {
    for (auto ch : str) if (ch == '-') ++ans;
  }
  std::cout << ans;
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

