/**
 * \link: https://www.luogu.com.cn/problem/P2251
 * \category: ST表 SparseTable 单调队列
 *
 * \date:
 * \author: YaeSaraki
 **/
#pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <cmath>
#include <deque>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

/** using SparseTable. */
const int kN = 1e6 + 233;
vector<vector<int> > ST(kN, vector<int>(21));
void initSparseTable(vector<int> &data) {
  int ld = data.size(), l2 = ceil(log2(ld)) + 1;
  for (int i = 0; i < ld; ++i) ST[i][0] = data[i];
  for (int j = 1; j < l2; ++j) {
    int pj = 1 << (j - 1);
    for (int i = 0; i + pj< ld; ++i) {
      ST[i][j] = min(ST[i][j - 1], ST[i + pj][j - 1]);
    }
  } 
}

int Query(int l, int r) {
  int lt = r - l + 1;
  int t = lt == 1 ? 0 : ceil(log2(lt)) - 1;
  return min(ST[l][t], ST[r - (1 << t) + 1][t]);
}

inline void solve() {
  int n, k; cin >> n >> k;
  vector<int> data(n);
  for (auto &it : data) cin >> it;
  initSparseTable(data);
  for (int i = k - 1; i < n; ++i) {
    cout << Query(i - k + 1, i) << '\n';
  }
  return;
}

/** using monotonic queue. */
inline void solve2() {
  int n, k; cin >> n >> k;
  vector<int> data(n);
  for (auto &it : data) cin >> it;
  vector<int> ans;
  deque<int> que;
  for (int i = 0; i < n; ++i) {
    while (que.size() && data.at(i) <= data.at(que.back())) que.pop_back(); 
    while (que.size() && que.front() <= i - k) que.pop_front();
    if (i >= k - 1) {
      if (que.size()) ans.push_back(data.at(que.front()));
      else ans.push_back(data.at(i));
    }
    que.push_back(i);
  }
  for (auto item : ans) cout << item << '\n';
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("/Users/Shared/test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
