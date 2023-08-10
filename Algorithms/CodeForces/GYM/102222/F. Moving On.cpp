/**
 * @problem: F. Moving On
 * @link: https://codeforces.com/gym/102222/problem/F
 * @category: floyd 动态规划
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

int n;
int rod;
const int kN = 233;
std::array<int, kN> risk, idx;
std::array<std::array<std::array<int, kN>, kN>, kN> dp;

inline void Floyd() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j][k] = std::min(dp[i][j][k - 1], dp[i][idx[k]][k  - 1] + dp[idx[k]][j][k - 1]);
      }
    }
  }
}

inline void solve() {
  std::cout << "Case #" << ++rod << ":\n";
  int q; std::cin >> n >> q;
  for (int i = 1; i <= n; ++i) { std::cin >> risk[i]; idx[i] = i; }
  auto cmp = [](const int a, const int b) { return risk[a] < risk[b]; };
  /* <!> 比较函数开始和结束位置一定要注意 */
  std::sort(idx.begin() + 1, idx.begin() + 1 + n, cmp);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cin >> dp[i][j][0];
    }
  }
  Floyd();

  while (q--) {
    int begin, end, threshold; std::cin >> begin >> end >> threshold;
    int thre = 0;
    for (int i = 1; i <= n; ++i) {
      if (threshold >= risk[idx[i]]) thre = i;
    }
    std::cout << dp[begin][end][thre] << "\n";
  }
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
