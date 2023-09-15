/**
 * \link: https://vjudge.csgrandeur.cn/problem/HDU-6570
 * \category: DP 动态规划
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

#define rep(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
using ll = long long;

inline void solve() {
  int n, c; while (cin >> n >> c) {
    vector<int> a(n + 1);
    vector<vector<int> > dp(c + 1, vector<int>(c + 1));
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) {
      int x = a[i];
      rep(j, 1, c) if (j != x) {
        if (dp[j][x] % 2 == 1) ++dp[j][x];
        if (dp[x][j] % 2 == 0) ++dp[x][j];
      }
    }
    int ans = 0;
    rep(i, 1, c) rep(j, 1, c) ans = max(ans, dp[i][j]);
    cout << ans << '\n';
  }
  return ;
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if(rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}