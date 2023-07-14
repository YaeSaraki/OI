/**
 * \link:
 * \category:
 *
 * \date:
 * \author: YaeSaraki
 **/
#pragma GCC optimize("O2")

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

const int kN = 1e5 + 233;
vector<vector<int> > ST(kN, vector<int>(31));

void initSparseTable(vector<int> data) {
  int ld = (int)data.size(), l2 = (int)ceil(log2(ld)) + 1;
  for (int i = 0; i < ld; ++i) ST[i][0] = data[i];
  for (int j = 1; j < l2; ++j) {
    int pj = 1 << (j - 1);
    for (int i = 0; i + pj < ld; ++i) {
      ST[i][j] = min(ST[i][j - 1], ST[i + pj][j - 1]);
    }
  }
}

int Query(int l, int r) {
  int lt = r - l + 1;
  int t = (lt == 1 ? 0 : ceil(log2(lt)) - 1);
  return min(ST[l][t], ST[r - (1 << t) + 1][t]);
}

inline void solve() {
  int n, q; cin >> n >> q;
  vector<int> data(n);
  for (auto &it : data) cin >> it;
  initSparseTable(data);
  while (q--) {
    int l, r; cin >> l >> r;
    cout << Query(l - 1, r - 1) << ' ';
  }
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
