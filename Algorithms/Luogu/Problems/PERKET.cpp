/**
 * @problem: P2036 [COCI2008-2009#2] PERKET
 * @link: https://www.luogu.com.cn/problem/P2036
 * @category: 模拟 Search
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

int n;
int ans = INT_MAX;
std::vector<int> acidityList, bitternessList;


/** u represent the corrent item */
void DFS(int u, int acidity, int bitterness) {
  if (acidity != 0 && bitterness != 0) ans = std::min(ans, (int)std::fabs(acidity - bitterness));

  /** 当u = n时， u - 1时的情况还未计算 */
  if (u == n) return;

  for (int i = u; i < n; ++i) {
    DFS(i + 1, acidity, bitterness);
    DFS(i + 1, acidity * acidityList[i],bitterness + bitternessList[i]);
  }

}

inline void solve() {
  std::cin >> n;
  /** 酸度 acidity, 苦度: bitterness */
  acidityList = std::vector<int> (n);
  bitternessList = std::vector<int> (n);
  for (int i = 0; i < n; ++i) std::cin >> acidityList[i] >> bitternessList[i];
  DFS(0, 1, 0);
  std::cout << ans << '\n';
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
