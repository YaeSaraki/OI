/**
 * @problem: 240. 食物链
 * @link: https://www.acwing.com/problem/content/242/
 * @category: 并查集
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

int lies;
/** 1 -> n 为主视角， 1 -> n 为同类，n + 1 -> 2n 为猎物， 2n + 1 -> 3n为天敌 */
std::vector<int> f;

int Find(int x) { return x == f[x] ? x : f[x] = Find(f[x]); }

bool Union(int x, int y) {
  if (x == y) return false;
  int a = Find(x), b = Find(y);
  f[a] = b;
  return true;
}

inline void solve() {
  int n, k; std::cin >> n >> k;
  f = std::vector<int> (3 * n + 1);
  std::iota(ALL(f), 0);
  while (k--) {
    int op, x, y; std::cin>> op >> x >> y;
    /* 如果 x 或者 y 大于 动物总数, 则是谎言 */
    if (x > n || y > n) { ++lies;
      continue; }

    switch(op) {
      case 1 : {
        /* 如果 x 的 猎物 是 y 或 x 的 天敌 是 y, 则是谎言 */
        if (Find(x + n) == Find(y) || Find(x + 2 * n) == Find(y)) { ++lies; break; }

        /* x 与 y 是 同类 */
        Union(x, y);

        /* x 的 猎物 是 y 的 猎物 */
        Union(x + n, y + n);

        /* x 的 天敌 是 y 的 天敌 */
        Union(x + 2 * n, y + 2 * n);

        break;
      }
      case 2 : {
        /* 如果 x 与 y 是 同类 或 x 的 天敌 是 y， 则是谎言 */
        if (Find(x) == Find(y) || Find(x + 2 * n) == Find(y)) { ++lies; break; }

        /* x 的 猎物 是 y */
        Union(x + n, y);

        /* y 的 天敌 是 x */
        Union(y + 2 * n, x);

        /* y 的 猎物 是 x 的 天敌 */
        Union(y + n, x + 2 * n);

        break;
      }
      default: break;
    }
  }
  std::cout << lies << '\n';
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

