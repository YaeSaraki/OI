/**
 * \link: https://www.luogu.com.cn/problem/P1111 
 * \category: 并查集 sort vector
 * 
 * \date: Tue Jul 11 10:12:01 CST 2023 
 * \author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

struct V {
  int v1, v2, t;
  bool operator<(const V &B) const {
    if (t != B.t) return t < B.t;
    return false;
  }
};

vector<int> f;
int Find(int u) { return f.at(u) == u ? u : f.at(u) = Find(f.at(u)); }

inline void solve() {
  int n, m; cin >> n >> m;
  /** init */
  V v[m];
  f = vector<int>(m + 1); // 这里f的大小为m + 1的原因是输入所给的村庄编号是从1开始的。
  iota(f.begin(), f.end(), 0);

  for (auto &elem : v) cin >> elem.v1 >> elem.v2 >> elem.t;
  /** 并查集. */
  sort(v, v + m);
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    int a = v[i].v1, b = v[i].v2;
    a = Find(a), b = Find(b);
    if (a != b) {
      f.at(a) = b;
      ++cnt;
    }
    if (cnt == n - 1) return cout << v[i].t << '\n', void();
  }
  cout << "-1\n";
  return ;
}

bool rt = false;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  // freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0); 
}