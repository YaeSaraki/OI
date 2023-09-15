#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

void inline solve() {
  int n; cin >> n;
  string str; cin >> str;
  // cout << str << '\n';
  int ans = 2, temp = 2;
  for (int i = 0; i < n - 1; ++i) {
    if (str[i] == str[i + 1]) {
      ++temp;
    } else {
      ans = max(ans, temp);
      temp = 2;
    }
  }
  cout << max(ans, temp) << '\n';
  return ;
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