/**
 * @problem: P8344 「Wdoi-6」走在夜晚的莲台野
 * @link: https://www.luogu.com.cn/problem/P8344
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  i64 x, y, z; std::cin >> x >> y >> z;

  bool isOK = true;
  while (isOK) {
    if (x > z) { isOK = false; break; }
    if ((z - 1 + z - x) * x / 2 + z - x < y)  { isOK = false; break; }
    break;
  }

  std::cout << (isOK ? "Renko\n" : "Merry\n");
}

bool rt = true;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}




