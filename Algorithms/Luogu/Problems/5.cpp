/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#define ONLINE_JUDGE
#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

const int kN = 1e6 + 233;
auto a = std::vector<int>(kN);
auto b = std::vector<int>(kN);

inline void solve() {
  int n; std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int jj = i;
    while (a[jj] < a[jj + 1]) ++jj;

    int j = jj;
    for (int k = 0; k <= n + 3; ++k) b[k] = a[k];
    if (i == j) b[j] = 0;
    while (b[j] < b[j + 1]) ++j;
    ans = std::max(ans, j - i + 1);



    
    for (int k = 0; k <= n + 3; ++k) b[k] = a[k];
    j = jj;
    if (j + 1 <= n) b[j + 1] = b[j] + 1;
    while (b[j] < b[j + 1]) ++j;
    ans = std::max(ans, j - i + 1);

    for (int k = 0; k <= n + 3; ++k) b[k] = a[k];
    j = jj;
    if (j <= n) b[j] = b[j - 1] + 1;
    while (b[j] < b[j + 1]) ++j;
    ans = std::max(ans, j - i + 1);

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
