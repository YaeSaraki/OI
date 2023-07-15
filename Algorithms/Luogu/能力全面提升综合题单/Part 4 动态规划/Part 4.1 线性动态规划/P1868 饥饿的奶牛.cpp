/** 
 * \link: https://www.luogu.com.cn/problem/P1868
 * \category: dp 动态规划
 * 
 * \date: Mon Jul 10 16:46:21 CST 2023
 * \note: 
 **/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using PI = pair<int, int>;

inline void solve() {
  int n; cin >> n;
  vector<PI> v(n + 1);
  vector<int> dp(n + 2);
  for (int i = 1; i <= n; ++i) {
    int x, y; cin >> x >> y;
    v.at(i) = {y, x};
  }
  sort(v.begin() + 1, v.end());
  // for (auto it : v) cout << it.first << " "; 
  for (int i = 1; i <= n; ++i) {
    int last = lower_bound(v.begin() + 1, v.begin() + 1 + i - 1, make_pair(v.at(i).second, 0)) - v.begin() - 1;
    int value = v.at(i).first - v.at(i).second + 1;
    dp.at(i) = max(dp.at(last) + value, dp.at(i - 1));
  }
  cout << dp.at(n) << '\n';
  return ;
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
