/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

std::vector<int> add(std::vector<int> &a, std::vector<int> &b) {
  if (a.size() < b.size()) return add(b, a);
  int t = 0;
  std::vector<int> c;
  size_t n = a.size();
  for (int i = 0; i < n; ++i) {
    t += a[i];
    if (i < b.size()) t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  if (t) c.push_back(1);
  return c;
}

inline void solve() {
  int begin, end; std::cin >> begin >> end;
  int dis = end - begin + 1;
  std::vector<std::vector<int> > f(dis + 1);
  f[0] = {0}, f[1] = {1};
  for (int i = 2; i <= dis; ++i) {
    f[i] = add(f[i - 1], f[i - 2]);
//    for (auto it : std::ranges::reverse_view(f[i])) std::cout << it;
//    std::cout << "\n";
  }
  for (auto it : std::ranges::reverse_view(f[dis])) std::cout << it;
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
