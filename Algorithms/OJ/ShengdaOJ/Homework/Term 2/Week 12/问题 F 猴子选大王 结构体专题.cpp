#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> a;

void inline solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) a.push_back(i);
  int i = 0, time = 1;
  while (a.size() != 1) {
    if (i == a.size()) i = 0;
    if (time == m) { a.erase(a.begin() + i); time = 1; }
    else ++time, ++i;
  }
  return cout << a[0] << endl, void();
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}