/**
 * @problem: 5081. 重复局面
 * @link: https://www.acwing.com/problem/content/5084/
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

auto m = std::map<std::string, int>();

inline void solve() {
  int n; std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string data;
    for (int j = 0; j < 8; ++j) {
      std::string temp;
      std::cin >> temp;
      data += temp;
    }
    std::cout << ++m[data] << "\n";
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
