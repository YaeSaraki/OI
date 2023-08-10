/**
 * @problem: 替换大师
 * @link: https://ac.nowcoder.com/acm/contest/62332/K
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using namespace std;
using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std:: cin >> n;
  std::string str; std::cin >> str;
  std::string tmp1(str),tmp2(str);
  bool flag = false;
  for (int i = 0; i < n; ++i) {
    char ch = str[i];
    if (ch == '(') {
      flag = true;
    }
    if (ch == ')') {
      flag = false;
      tmp1 = tmp2;
    }

    tmp1[i] = ch;
    if (flag && ch == ',') tmp2[i] = '.';
    else tmp2[i] = ch;
  }
  std::cout << tmp1;
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
