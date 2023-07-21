/**
 * @problem: P1037 [NOIP2002 普及组] 产生数
 * @link: https://www.luogu.com.cn/problem/P1037
 * @category: BFS 高精度
 * @date: Thu Jul 20 17:19:16 CST 2023
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <array>
#include <string>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;
using ll = long long;
using PI = pair<int, int>;

array<array<bool, 10>, 10> vis;

void Print(__int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) Print(x / 10);
  putchar(x % 10 + '0');
}

/** using floyd. */
inline void solve() {
  string nums; cin >> nums;
  int m; cin >> m;
  size_t len = nums.length();
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    vis[a][b] = true;
  }
  /** init floyd. */
  for (int k = 0; k < 10; ++k) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (vis[i][j] || (vis[i][k] && vis[k][j])) vis[i][j] = true;
      }
    }
  }
  for (int i = 0; i < 10; ++i) vis[i][0] = false, vis[i][i] = true;

  array<int, 10> value{};
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (vis[i][j]) ++value[i];
    }
  }

  __int128 ans = 1;
  for (int i = 0; i < len; ++i) {
    int num = nums[i] - '0';
    ans *= value[num];
  }
  Print(ans);
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
