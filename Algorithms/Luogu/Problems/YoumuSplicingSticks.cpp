/**
 * @problem: P3799 妖梦拼木棒
 * @link: https://www.luogu.com.cn/problem/P3799
 * @category: 暴力 枚举 组合 数学
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <climits>
#include <array>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

constexpr int MOD = 1e9 + 7, kN = 5001;
std::array<int, kN> stickBucket;

inline void solve() {
  int n; std::cin >> n;
  int lo = INT_MAX, hi = INT_MIN;
  for (int i = 0; i < n; ++i) {
    int x; std::cin >> x;
    ++stickBucket[x];
    lo = std::min(lo, x);
    hi = std::max(hi, x);
  }
  ll ans = 0;
  for (int i = lo + 1; i <= hi; ++i) {
    if (stickBucket[i] >= 2) {
      for (int j = lo; j <= (i >> 1); ++j) {
        if (stickBucket[j] && stickBucket[i - j]) {
          if (j == i - j) {
            /** <!> 如果前两根木棒长度相等的话, 那么咱需要判定这个长度的木棒够不够两个. */
            if (stickBucket[j] <= 1) continue;
            /**
             * <!!!> 取余不要用. +=
             * 这里用到了数学中的 排列组合. */
            ans = (ans + ((stickBucket[i] * (stickBucket[i] - 1) >> 1) % MOD) *
                         ((stickBucket[j] * (stickBucket[j] - 1) >> 1) % MOD)) % MOD;
          } else {
            ans = (ans + ((stickBucket[i] * (stickBucket[i] - 1) >> 1) % MOD) *
                         ((stickBucket[j] * stickBucket[i - j]) % MOD)) % MOD;
          }
        }
      }
    }
  }
  std::cout << ans << '\n';
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
