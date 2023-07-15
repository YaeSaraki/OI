/**
 * \problem: P2880 [USACO07JAN] Balanced Lineup G
 * \link: https://www.luogu.com.cn/problem/P2880
 * \category: SparseTable 树状树组
 * \date: Fri Jul 14 09:43:28 CST 2023 - Fri Jul 14 10:29:30 CST 2023
 * 
 **/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int kN = 2e5 + 233;
vector<vector<int> > ST1(kN, vector<int>(31));
vector<vector<int> > ST2(kN, vector<int>(31));

void initSparseTable(vector<int> data) {
  int ld = data.size(), l2 = (int)ceil(log2(ld)) + 1;
  for (int i = 0; i < ld; ++i) {
    ST1[i][0] = data.at(i);
    ST2[i][0] = data.at(i);
  }
  for (int j = 1; j < l2; ++j) {
    int pj = 1 << (j - 1);
    for (int i = 0; i + pj < ld; ++i) {
      ST1[i][j] = max(ST1[i][j - 1], ST1[i + pj][j - 1]);
      ST2[i][j] = min(ST2[i][j - 1], ST2[i + pj][j - 1]);
    }
  }
}

int Query(int l, int r, bool isMax) {
  int lt = r - l + 1;
  int t = lt == 1 ? 0 : (int) ceil(log2(lt)) - 1;
  if (isMax)  return max(ST1[l][t], ST1[r - (1 << t) + 1][t]);
  else        return min(ST2[l][t], ST2[r - (1 << t) + 1][t]);
}

inline void solve() {
  int n, q; cin >> n >> q;
  vector<int> data(n);
  for (auto &it : data) cin >> it;
  initSparseTable(data);
  while (q--) {
    int l, r; cin >> l >> r;
    int maxx = Query(l - 1, r - 1, true);
    int minn = Query(l - 1, r - 1, false);
//    cout << "test:" << maxx <<  ' ' << minn << '\n';
    cout << maxx - minn << '\n';
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
