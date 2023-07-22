/**
 * @problem: F. We Were Both Children
 * @link: https://codeforces.com/contest/1850/problem/F
 * @category: brute force implementation math number theory
 * @date:
 * @Author:
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;
using ll = long long;
using PI = pair<int, int>;

inline void solve() {
  int n; cin >> n;
  vector<int> ans(n + 1, 0), cnt(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x <= n) ++cnt[x];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) ans[j] += cnt[i];
  }

  cout << *max_element(ans.begin(), ans.end()) << '\n';
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
