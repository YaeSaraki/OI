/**
 * @problem: xinjun与阴阳师
 * @link: https://ac.nowcoder.com/acm/problem/14602
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <numeric>


#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = long long;
using PI = std::pair<int, int>;

const int kN = 1e3 + 233;


inline void solve() {
  std::vector<int> dp(kN * 1e2), a(kN);
  std::vector<std::vector<int> > w(kN, std::vector<int> (kN));
  std::vector<std::vector<int> > v(kN, std::vector<int> (kN));

  int n, m; std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    for (int j = 1; j <= a[i]; ++j) std::cin >> v[i][j];
    for (int j = 1; j <= a[i]; ++j) std::cin >> w[i][j];
  }
  
  
  for (int i = 1; i <= n; ++i) {
    for (int k = m; k >= 0; --k) {
      for (int j = 1; j <= a[i]; ++j) {
        if (k - w[i][j] >= 0) dp[k] = std::max(dp[k], dp[k - w[i][j]] + v[i][j]);
      }
    }
  }
  std::cout << dp[m] << "\n";
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



