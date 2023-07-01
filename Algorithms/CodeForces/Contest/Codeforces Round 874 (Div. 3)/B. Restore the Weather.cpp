/**
 * \link: https://codeforces.com/contest/1833/problem/B
 * \category: greedy sortings *900
 * 
 * 
 * 
 * 
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using PI = pair<int, int>;

bool cmp(PI &A, PI &B) {
  if (A.second != B.second) return A.second < B.second;
  return false;
}

inline void solve() {
  int n, k; cin >> n >> k;
  vector<PI> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) { int x; cin >> x; a[i] = {i, x}; }
  for (int i = 0; i < n; ++i) cin >> b[i];
  sort(a.begin(), a.end(), cmp);
  sort(b.begin(), b.end());
  int i = 0;
  for (auto &it : a) { it.second = b[i++]; }
  sort(a.begin(), a.end());
  for (auto it : a) cout << it.second << " ";
  cout << '\n';
  return ;
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