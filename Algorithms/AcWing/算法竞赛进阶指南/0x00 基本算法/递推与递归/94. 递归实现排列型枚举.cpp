/**
 * \link: https://www.acwing.com/problem/content/96/
 * \category: 递归
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<int> path;

void DFS(int u, int state) {
  if (u == n) {
    for (auto it : path) cout << it << ' ';
    cout << '\n';
    return ;
  }
  for (int i = 0;  i < n; ++i) {
    if (!(state >> i & 1)) {
      path.push_back(i + 1);
      DFS(u + 1, state | 1 << i);
      path.pop_back();
    }
  }
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