/**
 * @problem: P1219 [USACO1.5] 八皇后 Checker Challenge
 * @link: https://www.luogu.com.cn/problem/P1219
 * @category: DFS 
 * @date: Mon Jul 17 08:54:13 CST 2023
 * @author: YaeSaraki
 **/

// #pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <set>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

int n;
vector<bool> r, rc, cr;
vector<int> board;
set<double> slopeSet;
int times = 0; // int times: Record the number of conditions conformed.

void Print() {
  if (times <= 3) for (int i = 0; i < board.size(); ++i)
      cout << board.at(i) << " \n"[i == board.size() - 1];
}

void DFS(int u) { // int u: represent the corrent row.
  if (u == n) { ++times; Print(); return; }
  for (int i = 0;  i < n; ++i) {
    int t1 = i - u + n, t2 = i + u; // int t1, t2: Respectively represent oblique line(/ & \).

    if (!r.at(i) && !rc.at(t1) && !cr.at(t2)) { // Judge whether the condition conformed.
      /** tag the corrent column, ablique line. */
      r.at(i) = rc.at(t1) = cr.at(t2) = true;
      board.push_back(i + 1);

      /** Search the next row. */
      DFS(u + 1);

      /** Remove the tag, backtrack. */
      r.at(i) = rc.at(t1) = cr.at(t2) = false;
      board.pop_back();

    }
  }
} 

inline void solve() {
  cin >> n;
  rc = cr = vector<bool> (2 * n);
  r = vector<bool> (n);
  DFS(0);
  cout << times << '\n';
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
