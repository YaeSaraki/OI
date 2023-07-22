/**
 * @problem: D. Balanced Round
 * @link: https://codeforces.com/contest/1850/problem/D
 * @category: brute force greedy implementation sortings
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define DBG(x) cout << #x << " = " << (x) << '\n'


using namespace std;
using ll = long long;
using PI = pair<int, int>;

inline void solve() {
  int n, k; cin >> n >> k;

  vector<int> v(n);
  for (auto &it : v) cin >> it;

  if (n == 1) {
    cout << "0\n";
    return;
  }

  sort(v.begin(), v.end());

  int maxx = 0;
  for (int i = 1; i < n; ++i) {
    int j = i;
    while (j < n && v[j] - v[j - 1] <= k) ++j;
    maxx = max(maxx, j - i + 1);
    i = j;
  }
  cout << n - maxx << '\n';
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
