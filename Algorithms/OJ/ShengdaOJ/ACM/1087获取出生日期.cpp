/**
 * @problem: 1087: 获取出生日期（多实例测试)
 * @link: http://acm.shengda.edu.cn/problem.php?id=1087
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
  std::string year, month, day, drop;
  std::cin >> std::setw(6) >> drop >>
              std::setw(4) >> year >>
              std::setw(2) >> month >>
              std::setw(2) >> day >>
              std::setw(4) >> drop;
  std::cout << year << '-' << month << '-' << day << '\n';
//  DBG(drop);
}

bool rt = true;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
