#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define int long long

void inline solve() {
  int n; cin >> n;
  vector<vector<int> > a(n + 1, vector<int> (n + 1));
  a[0][0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j) a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
      else a[i][j] = a[i - 1][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) cout << a[i][j] << " ";
    cout << '\n';
  }
  return;
}

bool rt = false;
signed main() {
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}