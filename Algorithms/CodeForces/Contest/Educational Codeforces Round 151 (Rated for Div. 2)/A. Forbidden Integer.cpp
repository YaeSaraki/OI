/**
 * \link: https://codeforces.com/contest/1845/problem/A
 * \category: constructive algorithms implementation math
 * 
 * 
 * 
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

void inline solve() {
  int n, k, x;
  cin >> n >> k >> x;
  if (x != 1) {
    cout << "YES\n" << n << '\n';
    for (int i = 0; i < n; ++i) cout << "1 ";
    return cout << '\n', void();

  } else if (k == 2 && !(n & 1)) {
    cout << "YES\n" << n / 2 << '\n';
    for (int i = 0; i < n / 2; ++i) cout << "2 ";
    return cout << '\n', void();

  } else if (k >= 3) {
    cout << "YES\n" << (n >> 1) << '\n';
    if (!(n & 1)) {
      for (int i = 0; i < (n >> 1); ++i) cout << "2 ";
      cout << '\n';
    } else {
      for (int i = 0; i < (n >> 1) - 1; ++i) cout << "2 ";
      cout << "3\n";
    }
    return ;
  }
  return cout << "NO\n", void();
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}