/**
 * \link: https://www.luogu.com.cn/problem/P1198
 * \category: SparseTable
 *
 * \date:
 * \author: YaeSaraki
 **/
// #pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <cmath>
#define DBG(x) cout << #x << " = " << (x) << '\n'
#define int long long

using namespace std;

const int kN = 2e5 + 233;
int n = 0;
vector<int> a(kN);
vector<vector<int> > ST(kN, vector<int>(31));

void UpdateSparseTable() {
  ST[n][0] = a[n];
  for (int j = 1; (1 << j) <= n; ++j) {
    ST[n][j] = max(ST[n][j - 1], ST[n - (1 << (j - 1))][j - 1]);
  }
}

int Query(int l, int r) {
  int lt = r - l + 1;
  int t = lt == 1 ? 0 : ceil(log2(lt)) - 1;
  return max(ST[r][t], ST[l + (1 << t) - 1][t]);
}

inline void solve() {
  int q, MOD; cin >> q >> MOD;
  int t = 0;
  while (q--) {
    char ch; cin >> ch;
    switch(ch) {
      case 'A': {
        int x; cin >> x;
        a[++n] = (x + t) % MOD;
        UpdateSparseTable();
        break;
      }
      case 'Q' : {
        int x; cin >> x;
        cout << (t = Query(n - x + 1, n)) << '\n';
        break;
      }
    }
  }
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
