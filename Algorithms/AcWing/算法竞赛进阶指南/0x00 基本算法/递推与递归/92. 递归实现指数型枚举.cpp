/**
 * \link: https://www.acwing.com/problem/content/94/
 * \category: 递归
 * 
 * 
 * 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;

void DFS(int u, int state) {
  if (u == n) {
    for (int i = 0; i < n; ++i)
      if (state >> i & 1) cout << i + 1 << " ";
    cout << '\n';
    return ; // * 这里需要终止 否则DFS函数会一直进行下去导致段错误. (DFS 终止条件)
  }
  DFS(u + 1, state), DFS(u + 1, state | 1 << u);
  return ;
}

inline void solve() {
  cin >> n;
  DFS(0, 0);
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