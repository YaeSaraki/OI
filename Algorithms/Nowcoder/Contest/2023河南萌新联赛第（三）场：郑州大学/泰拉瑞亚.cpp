/**
 * @problem: 泰拉瑞亚
 * @link: https://ac.nowcoder.com/acm/contest/62332/L
 * @category: 模拟
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
#define int long long

using namespace std;
using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
  int n, hp; std::cin >> n >> hp;
  std::vector<PI> weapons(n);
  for (int i = 0; i < n; ++i) std::cin>> weapons[i].second >> weapons[i].first;

  std::sort(ALL(weapons));

  int normal_max_index = 0;
  for (int i = 0;  i < n; ++i) {
    if (weapons[i].second >= weapons[normal_max_index].second) {
      if (weapons[i].second == weapons[normal_max_index].second) {
        if (weapons[i].first < weapons[normal_max_index].first)
          normal_max_index = i;
      } else {
        normal_max_index = i;
      }
    }
  }
//  DBG(weapons[normal_max_index].second);
//  for (auto it : weapons) std::cout << it.first << " ";
  int times = 0;

  for (int i = n - 1; ~i; --i) {
    if (i == normal_max_index) continue;
//    DBG(weapons[i].first), DBG(weapons[normal_max_index].second);
    if (weapons[i].first <= weapons[normal_max_index].second) break;

    if (hp <= weapons[normal_max_index].first) return cout << times + 1, void();

    hp -= weapons[i].first;
    ++times;
    if (hp <= 0) break;
  }

//  DBG(hp);

  while (hp > 0) {
    if (hp <= weapons[normal_max_index].first) return cout << times + 1, void();

    hp -= weapons[normal_max_index].second;
    ++times;
  }
  cout << times;
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
