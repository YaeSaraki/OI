/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include <string>
#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

std::vector<int> add(std::vector<int> a, std::vector<int> b) {
  std::vector<int> c;
  size_t len1 = a.size(), len2 = b.size();
  if (len1 < len2) return add(b, a);
  size_t t = 0;
  for (size_t i = 0; i < len1; ++i) {
    if (i < len1) t += a[i];
    if (i < len2) t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  if (t) c.push_back(1);
  return c;
}

inline void solve() {
   std::string str1, str2; std::cin >> str1 >> str2;
   std::vector<int> a, b;
   for (char & ch : std::ranges::reverse_view(str1)) a.push_back(ch - '0');
   for (char & ch : std::ranges::reverse_view(str2)) b.push_back(ch - '0');
   std::vector<int> ans = add(a, b);
   for (int & an : std::ranges::reverse_view(add(a, b))) std::cout << an;
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
