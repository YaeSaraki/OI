/**
 * @problem: P5194 [USACO05DEC] Scales S
 * @link: https://www.luogu.com.cn/problem/P5194
 * @category: DFS
 * @date: Mon Jul 17 10:57:54 CST 2023
 * @author: YaeSaraki
 **/
// #pragma GCC optimize("O2")

#include <algorithm>
#include <iostream>

#define DBG(x) cout << #x << " = " << (x) << '\n'
#define int ll

using namespace std;
using ll = long long;

int n, max_w;
int maxWeight = 0;
vector<int> weights;
vector<int> sub = {0};

void DFS(int u, int w) {
  maxWeight = max(maxWeight, w);

  if (u == -1) return;
  if (w + sub.at(u + 1) <= max_w) {
    maxWeight = max(maxWeight, w + sub.at(u + 1));
    return;
  }

  DFS(u - 1, w);
  if (w + weights.at(u) <= max_w) DFS(u - 1, w + weights.at(u));
}

inline void solve() {
  cin >> n >> max_w;
  weights = vector<int>(n);  
  for (int &it : weights) {
    cin >> it;
    sub.push_back(it + *sub.rbegin());
  }
  while (max_w < *weights.rbegin()) weights.pop_back();
  n = weights.size();
  DFS(n - 1, 0);
  cout << maxWeight << '\n';
}

bool rt = false;
signed main() {
  // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
