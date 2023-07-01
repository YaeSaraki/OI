/**
 * \link: https://codeforces.com/contest/1833/problem/C
 * \category: greedy math *800
 * 
 * 
 * 
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

inline void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &it : a) cin >>it;
  sort(a.begin(), a.end());
  if (a[0] & 1) return cout << "YES\n", void();
  for (auto it : a) if (it & 1) 
    return cout << "NO\n", void();
  return cout << "YES\n", void();
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}