#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

inline void solve() {
  string str; cin >> str;
  set<char> s;
  for (auto ch : str) s.insert(ch); 
  if (s.size() == 1) cout << "-1" << '\n';
  else cout << str.size() - 1 << '\n';
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