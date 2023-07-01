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
#include <map>
#include <numeric>
#include <set>

using namespace std;

int n;
const int kN = 2023;
int ne[kN], enemy[kN];

int find(int x) { return ne[x] == x ? x : find(ne[x]); }
void join(int x, int y) { ne[find(x)] = find(y); }

inline void init() {
  memset(enemy, 0, sizeof enemy);
  iota(ne + 1, ne + 1 + n, 1);
}

inline void solve() {
  int flag = 0;
  int q; cin >> n >> q;
  
  if (flag) cout << "No suspicious bugs found!" << '\n';
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