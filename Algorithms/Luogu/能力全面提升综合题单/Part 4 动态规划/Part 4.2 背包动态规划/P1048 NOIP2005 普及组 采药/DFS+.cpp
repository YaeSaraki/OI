#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int kN = 1001;
int w[kN], v[kN], mem[kN][kN];
int m, n;
int ans = 0;

int dfs(int pos, int tleft) {
  if (mem[pos][tleft] != -1) return mem[pos][tleft];
  if (pos == m + 1) { return mem[pos][tleft] = 0; }
  int dfs1 = dfs(pos + 1, tleft);
  int dfs2 = tleft >= w[pos] ? dfs(pos + 1, tleft - w[pos]) + v[pos] : 0;
  return mem[pos][tleft] = max(dfs1, dfs2);
}

inline void solve() {
  cin >> n >> m;
  memset(mem, -1, sizeof(mem));
  for (int i = 1; i <= m; ++i) cin >> w[i] >> v[i];
  return cout << dfs(1, n) << endl, void();
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