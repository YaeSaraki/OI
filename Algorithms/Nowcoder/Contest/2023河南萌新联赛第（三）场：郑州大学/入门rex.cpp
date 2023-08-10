/**
 * @problem: 入门mex
 * @link: https://ac.nowcoder.com/acm/contest/62332/B
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>
#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using namespace std;
using ll = long long;
using PI = std::pair<int, int>;

int n, num;
std::vector<int> a;
std::vector<bool> vis;
std::vector<int> s;

void DFS(int u) {
  if (u > 10) return;
  for (int i = 0; i < n; ++i) {
    if(!vis[i]) {
      vis[i] = true;
      num += a[i];
      s.push_back(num);
      DFS(u + 1);
      vis[i] = false;
      num -= a[i];
    }
  }
}

inline void solve() {
  std::cin >> n;
  s.reserve(1e7);
  a = std::vector<int> (n);
  vis = std::vector<bool> (n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(ALL(a));
  DFS(0);
  std::sort(ALL(s));
  n = std::unique(ALL(s)) - s.begin();
  for (int i = 0; i < n; ++i) {
    if (s[i] != s[0] + i) return cout << s[0] + i, void();
  }
  cout << s[n - 1];
}

bool rt = false;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
