/**
 * @problem:
 * @link:
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

using i64 = long long;
using PI = std::pair<int, int>;

int n, m;
auto c = std::vector<int>();

inline int lowbit(int x) { return x & -x; }

void add(int x, int k) {
  while (x <= n) c[x] += k, x += lowbit(x);
}

int getSum(int x) {
  int sum = 0;
  while (x) sum += c[x], x -= lowbit(x);
  return sum;
}

inline void solve() {
  std::cin >> n >> m;
  c = std::vector<int>(n + 1);
  for (int i = 1; i <= n; ++i) { int x; std::cin >> x; add(i, x); }
  while (m--) {
    int op; std::cin >> op;
    if        (op == 1) {
      int x, k; std::cin >> x >> k;
      add(x, k);
    } else if (op == 2) {
      int left, right; std::cin >> left >> right;
      std::cout << getSum(right) - getSum(left - 1) << "\n";
    }
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

