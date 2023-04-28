#include <iostream>
#include <algorithm>
using namespace std;

const int kN = 1001;
int w[kN], v[kN];
int m, n;
int ans = 0;
void dfs(int pos, int tleft, int val) {
  if (tleft < 0) return;
  if (pos == m + 1) {
    ans = max(ans, val);
    return ;
  }
  dfs(pos + 1, tleft, val), dfs(pos + 1, tleft - w[pos], val + v[pos]);
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> w[i] >> v[i];
  dfs(1, n, 0);
  return cout << ans << endl, void();
}

bool rt = false;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}