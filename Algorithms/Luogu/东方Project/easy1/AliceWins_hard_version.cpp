/**
 * @problem: P7940 「Wdcfr-1」Alice Wins! (hard version)
 * @link: https://www.luogu.com.cn/problem/P7940
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long
#define ONLINE_JUDGE
using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  int n; std::cin >> n;
  int m = n + n;
  
  auto a = std::vector<int>(m);
  auto b = std::vector<int>(m);
  auto aa = std::vector<int>(m, -1); 
  auto bb = std::vector<int>(m, -1); 

  for (auto &it : a) std::cin >> it;
  for (auto &it : b) std::cin >> it;
  
  int chance_a = n, chance_b = n;

  /** 使A获胜. */
  for (int i = 0; i < m; ++i) {
    int t = a[i] % 3 + 1;
    if (b[i] == t) continue;

    if (chance_b) {
      --chance_b;
      bb[i] = b[i];
      b[i] = t;
      continue;
    }

    t = (b[i] + 1) % 3 + 1;
    if (a[i] == t) continue;

    if (chance_a) {
      --chance_a;
      aa[i] = a[i];
      a[i] = t;
      continue;
    }
  }

  // DBG(chance_a), DBG(chance_b);
  for (int i = 0; i < m; ++i) {
    if (chance_a && chance_b && (aa[i] == -1 && bb[i] == -1)) { 
      aa[i] = a[i], bb[i] = b[i];
      a[i] = a[i] % 3 + 1;
      b[i] = b[i] % 3 + 1;
      --chance_a, --chance_b;
      continue;
    }
    if (chance_a && (aa[i] == -1 && bb[i] != -1)) {
      do {
        a[i] = a[i] % 3 + 1;
        b[i] = b[i] % 3 + 1;
      } while (aa[i] == a[i] || bb[i] == b[i]);
      --chance_a;
      continue;
    }
    if (chance_b && (bb[i] == -1 && aa[i] != -1)) {
      do {
        a[i] = a[i] % 3 + 1;
        b[i] = b[i] % 3 + 1;
      } while (bb[i] == b[i] || aa[i] == a[i]);
      --chance_b;
      continue;
    }
  }

  std::cout << m << '\n';
  for (auto it : a) std::cout << it << " ";
  std::cout << '\n';
  for (auto it : b) std::cout << it << " ";
  std::cout << '\n';
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

