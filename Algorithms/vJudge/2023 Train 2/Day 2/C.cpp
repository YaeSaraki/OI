#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

#define ONLINE_JUDGE

using i64 = int64_t;
using PI = std::pair<int, int>;


inline void solve() {
  int x_end, y_end; std::cin >> x_end >> y_end;
  int times; std::cin >> times;
  std::string op; std::cin >> op;

  int x = 0, y = 0;
  while (times--) {
    for (int i = 0; i < op.length(); ++i) {
      switch(op[i]) {
        case 'U': ++y; break;
        case 'D': --y; break;
        case 'L': --x; break;
        case 'R': ++x; break;
      }
      if (x == x_end && y == y_end) return std::cout << "YES\n", void();
    }
  }
  std::cout << "NO\n";
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
