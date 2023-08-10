/**
 * @problem: P1616 疯狂的采药
 * @link: https://www.luogu.com.cn/problem/P1616
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
#define int long long

using ll = long long;
using PI = std::pair<int, int>;

int n, p;

std::vector<int> mul(std::vector<int> a, std::vector<int> b) {
  std::vector<int> c(11);
  if (a.size() < b.size()) return mul(b, a);
  for (int i = 0; i < std::min((ll)a.size(), (ll)11); ++i) {
    for (int j = 0; j < std::min((ll)b.size(), (ll)11); ++j) {
      if (i + j <= 11) c[i + j] += a[i] * b[j];
    }
  }
  int t = 0;
  for (int i = 0; i < c.size(); ++i) {
    t += c[i];
    c[i] = t % 10;
    t /= 10;
  }

  return c;
}
int qPow(int a, int n) {
  int res = 1 % p;
  while (n) {
    if (n & 1) res = res * a % p;
    a = a * a;
  }
  return res;
}


std::vector<int> qPow(std::vector<int> a, int n) {
  std::vector<int> res = {1};
  while (n) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a);
  }
  return res;
}


inline void solve() {

  std::vector<int> temp = {2}, temp2 = {2};

  int t = qPow(2, n);
  std::vector<int> ans = qPow(temp, t);

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