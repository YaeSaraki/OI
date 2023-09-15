#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;


int a[105], f[2][105];

inline void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) for (int j = 0; j < i; ++j) if (a[i] > a[j]) f[0][i] = max(f[0][i], f[0][j] + 1);
  for (int i = n; i >= 1; --i) for (int j = n + 1; j > i; --j) if (a[i] > a[j]) f[1][i] = max(f[1][i], f[1][j] + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, f[0][i] + f[1][i] - 1);
  return cout << n - ans << endl, void();
  // for (int i = 1; i <= n; ++i) cout << f[1][i] << " ";
}

int rt = false;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}