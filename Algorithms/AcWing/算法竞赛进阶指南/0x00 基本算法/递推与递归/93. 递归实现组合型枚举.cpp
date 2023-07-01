/**
 * \link: https://www.acwing.com/problem/content/95/
 * \category: 递归
 * 
 * 
 * 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

void DFS(int t, int u, int state) {
  if (u == n + 1) return ;
  if (t == m) {
    for (int i = 0; i < n; ++i)
      if (state >> i & 1) cout << i + 1 << " ";
    cout << '\n';
    return ; 
  }
  DFS(t + 1, u + 1, state | 1 << u), DFS(t, u + 1, state);
}

inline void solve() {
  cin >> n >> m;
  DFS(0, 0, 0);
  return ;
}

bool rt = false;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}