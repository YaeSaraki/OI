/**
 * @problem: P1588 [USACO07OPEN] Catch That Cow S
 * @link: https://www.luogu.com.cn/problem/P1588
 * @category: DFS
 * @date: Tue Jul 18 08:51:16 CST 2023
 * @author: YaeSaraki
 **/
// #pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector> 

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;

const int kN = 100100;

int getSteps(int fj, int cow) {
  if (fj >= cow) return fj - cow;
  vector<int> haspassed(2 * cow);
  haspassed[0] = true;
  queue<pair<int, int> > que;
  que.push({fj, 0});
  while (que.size()) {
    auto now = que.front(); que.pop();
    int now_pos = now.first, next_step = now.second + 1;
    if (now_pos == cow) return now.second;
    haspassed[now_pos] = true;
    /** 1. 2. 3. */
    int next_pos;
    /** 1. */ 
    next_pos = now_pos + 1;
    if (next_pos <= cow && !haspassed[next_pos])
      que.push({next_pos, next_step});
    /** 2. */
    next_pos = now_pos - 1;
    if (!haspassed[next_pos])
      que.push({next_pos, next_step});
    /** 3. */
    next_pos = now_pos * 2;
    if (next_pos < cow * 2 && !haspassed[next_pos])
      que.push({next_pos, next_step});
  }
  return -1;
}

inline void solve() {
  int fj, cow; cin >> fj >> cow;
  cout << getSteps(fj, cow) << '\n';
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
