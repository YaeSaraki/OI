#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  std::string str; std::cin >> str;
  size_t n = str.length();
  i64 ans = 0;
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i < n; ++i) {
      bool flag = true;
      for (int j = 1; j < len; ++j) {
        if (str[i] != str[i + 1]) flag = false;
      }
      if (flag) ++ans;
    }
  }
  std::cout << ans << "\n";
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
