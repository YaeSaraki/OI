#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'
const int MOD = 1e9 + 7;

inline void solve() {
  int n, w; cin >> n >> w;
  int a[n + 1], dp[w + 1] = {1};
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= w; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[j] <= i) dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
    }
  }

  return cout << dp[w] << endl, void();
}

bool tc = false;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (tc) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}