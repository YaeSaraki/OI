/**
 * @problem: E. Cardboard for Pictures
 * @link: https://codeforces.com/contest/1850/problem/E
 * @category: binary search implementation math
 * @date:
 * @Author:
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
#define int long long

using namespace std;
using ll = long long;
using PI = pair<int, int>;

inline void solve() {
  int n, c; cin >> n >> c;
  vector<int> a(n);
  for (int i = 0 ; i < n; ++i) cin >> a[i];
  int left = 1, right = 1e9;
  while (left <= right) {
    int area = 0;
    int mid = left + ((right - left) >> 1);
    for (int i = 0; i < n ; ++i) {
      int side_length = (a.at(i) + 2 * mid);
      area += side_length * side_length;
      if (area > c) break;
    }
    if (area == c) return cout << mid << '\n', void();
    if (area < c) left = mid + 1;
    else right = mid - 1;
  }

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
