/**
 * @problem: 3384. 二叉树遍历
 * @link: https://www.acwing.com/problem/content/3387/
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

int k;
std::string str;

/**
 *  Q : 给出前序遍历, 用 # 作为结束标志
 *  1 : 输出前序遍历
 *  2 : 输出中序遍历
 *  3 : 输出后序遍历
 **/
const int op = 1;

void dfs() {
  if (k > str.length()) return;
  if(str[k] == '#') {
    str[k++];
    return;
  }
  char root = str[k++];
  if (op == 1) std::cout << root << " ";
  dfs();
  if (op == 2) std::cout << root << " ";
  dfs();
  if (op == 3) std::cout << root << " ";
}

inline void solve() {
  std::cin >> str;
  dfs();
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
