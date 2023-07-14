/**
 * \link: https://www.luogu.com.cn/problem/P3865
 * \category: ST表 SparseTable
 *
 * \date:
 * \author: YaeSaraki
 **/
// #pragma GCC optimize("O2")

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

const int kN = 1e5 + 233;
vector<vector<int> > ST(kN, vector<int>(31));

void initSparseTable(vector<int> a) {
  int la = a.size(), l2 = ceil(log2(la)) + 1;
  for (int i = 0; i < la; ++i) ST[i][0] = a[i];
  for (int j = 1; j < l2; ++j) {
    int pj = 1 << (j - 1);
    for (int i = 0; i + pj < la; ++i) {
      ST[i][j] = max(ST[i][j - 1], ST[i + pj][j - 1]);
    }
  }
}

int Query(int l, int r) {
  int lt = r - l + 1;
  int t = lt == 1 ? 0 : ceil(log2(lt)) - 1;
  return max(ST[l][t], ST[r - (1 << t) + 1][t]);
}

inline void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a.at(i);
  initSparseTable(a);
  while (q--) {
    int l, r; cin >> l >> r;
    cout << Query(l - 1, r - 1) << '\n';
  }
  return;
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
