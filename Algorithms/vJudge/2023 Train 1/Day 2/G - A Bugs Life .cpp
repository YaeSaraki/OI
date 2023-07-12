/**
 * https://vjudge.csgrandeur.cn/problem/HDU-1829
 * \category: 并查集
 * 
 * 
 * 
*/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>

using namespace std;

int n;
int t = 0;
const int kN = 100100;
int f[2 * kN];

int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]); }

inline void solve() {
  int flag = 0;
  int q; cin >> n >> q;
  iota(f, f + (n * 2) + 1, 0);
  for (int i = 0; i < q; ++i) {
    int x, y; cin >> x >> y;
    if (flag) continue;
    /** Find x & y. */
    x = Find(x), y = Find(y);
    /** Union. */
    int a = Find(x + n), b = Find(y + n);
    if (x != y) f[a] = y, f[b] = x;
    else flag = 1;
  }
  cout << "Scenario #" << ++t << ":\n"; 
  if (!flag) cout << "No suspicious bugs found!" << '\n';
  else cout << "Suspicious bugs found!" << '\n';
}

bool rt = true;
signed main () {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}