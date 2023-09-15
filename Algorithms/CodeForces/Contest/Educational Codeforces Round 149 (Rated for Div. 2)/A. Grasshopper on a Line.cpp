
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

void inline solve() {
  int n, k; cin >> n >> k;
  if (n % k) return cout << "1\n" << n << '\n', void();
  else cout << "2\n" << n - 1 << " " << 1 << '\n', void();
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