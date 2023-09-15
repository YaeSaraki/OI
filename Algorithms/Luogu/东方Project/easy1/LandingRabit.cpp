
/**
 * @problem: P7870 「Wdoi-4」兔已着陆
 * @link: https://www.luogu.com.cn/problem/P7870
 * @category: 
 * @date: 
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;

inline void solve() {
  auto stk = std::stack<PI>();
  int n; std::cin >> n;
  for (int _i = 0; _i < n; ++_i) {
    int op; std::cin >> op;
    switch(op) {
      case 1 : {
                 int left, right; std::cin >> left >> right;
                 stk.emplace(left, right);
                 break;
               }
      case 2 : {
                 i64 x; std::cin >> x;
                 i64 ans = 0;
                 while (x) {
                    auto [left, right] = stk.top(); stk.pop();
                    i64 t = right - left + 1;
                    //DBG(t);
                    if (x >= t) {
                      x -= t;
                      ans += (left + right) * 1LL * t / 2;
                    } else     {
                      ans += (right - x + 1 + right) * 1LL * x / 2;
                      stk.emplace(left, right - x);
                      x = 0;
                    } 
                 }
                 std::cout << ans << "\n";
               }

    }
  }
}

/* 模拟Stack + 前缀和 50point */
inline void solve2() {
  int n; std::cin >> n;
  const int kN = 6e6 + 233;
  
  int top = 0;
  auto stk = std::vector<i64>(kN);
  for (int _i = 0; _i < n; ++_i) {
    int op; std::cin >> op;
    switch(op) {
      case 1: {
                int left, right; std::cin >> left >> right;
                for (int i = left; i <= right; ++i) {
                  ++top;
                  stk[top] = i + stk[top - 1];
                  //DBG(stk[top]);
                }
                break;
              }
      case 2: {
                int x; std::cin >> x;
                //DBG(x);
                std::cout << stk[top] - stk[top - x] << "\n";
                top -= x;
                break;
              }
    }
    
  }
  
}

/* stack 50point */
inline void solve1() {
  int n; std::cin >> n;
  auto que = std::stack<int>();
  while (n--) {
    int op; std::cin >> op;
    switch(op) {
      case 1: {
                int left, right; std::cin >> left >> right;
                for (int i = left; i <= right; ++i) que.emplace(i);
                break;
              }
      case 2: {
                int x; std::cin >> x;
                i64 ans = 0;
                do {
                  ans += que.top();
                } while (que.pop(), --x);
                std::cout << ans << "\n";
              }
    }
  }
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
