/**
 * \link: https://www.acwing.com/problem/content/93/
 * \category: 位运算 二进制 状态压缩DP
 * 
 * 
 * 
*/
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using ull = unsigned long long;

const int kN = 20, kM = 1 << 20;
int f[kM][kN], weight[kN][kN]; 

inline void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> weight[i][j];
  memset(f, 0x3f, sizeof f);
  f[1][0] = 0;
  for (int i = 0; i < 1 << n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        for (int k = 0; k < n; ++k) {
          if (i ^ (1 << j) >> k & 1)
            f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + weight[k][j]);
        }
      }
    }
  }
  return cout << f[(1 << n) - 1][n - 1] << '\n', void();
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}