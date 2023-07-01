#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;



inline void solve() {
  set<string> a, b;
  int n; cin >> n;
  string temp;
  for (int i = 0; i < n; ++i) { cin >> temp; a.insert(temp); }
  int m; cin >> m;
  for (int i = 0; i < n; ++i) { cin >> temp; a.insert(temp); }
  cin >> temp;
  
  for (int i = 0; i < temp.size(); ++i) {
    
  }
}

bool rt = false;
int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return 0;
}