/**
 * @problem: P3368 【模板】树状数组 2
 * @link: https://www.luogu.com.cn/problem/P3368
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

int n;
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
  int q; std::cin >> n >> q;
  c = std::vector<int>(n + 1);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int x; std::cin >> x;
    add(i, x - cnt);
    cnt = x; 
  }
  while (q--) {
    int op; std::cin >> op;
    if        (op == 1) {
      int left, right, k; std::cin >> left >> right >> k;
      add(left, k), add(right + 1, -k);
    } else if (op == 2) {
      int x; std::cin >> x;
      std::cout << getSum(x) << "\n";
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

