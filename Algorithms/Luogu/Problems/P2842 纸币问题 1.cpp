#include <algorithm>
#include <cstring>
#include <iostream>

#define endl '\n'
using namespace std;

inline void solve() {
  int n, w; cin >> n >> w;
  int a[n + 1] = {0};
  int dp[w + 1];
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = a[i]; j <= w; ++j) dp[j] = min(dp[j - a[i]] + 1, dp[j]);
  }
  cout << dp[w] << endl;
  return ;
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