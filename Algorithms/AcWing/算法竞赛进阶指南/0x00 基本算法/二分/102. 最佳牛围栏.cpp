/**
 * @problem: 102. 最佳牛围栏
 * @link: https://www.acwing.com/problem/content/description/104/
 * @category: 二分 前缀和 双指针
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using ll = long long;
using PI = std::pair<int, int>;

int n, f;
std::vector<int> fence;
std::vector<double> sum;

/* 二分条件 */
bool check(double avg) {
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + (fence[i] - avg);
  }
  double minn = 0;
  for (int i = 0, j = f; j <= n; ++i, ++j) {
    minn = std::min(minn, sum[i]);
    if (sum[j] - minn >= 0) return true;
  }
  return false;
}

inline void solve() {
  std::cin >> n >> f;
  fence = std::vector<int> (n + 1);
  sum = std::vector<double> (n + 1);

  /* 二分: 纪录最大值 划分查找区间. */
  double left = 0, right = 0;
  for (int i = 1; i <= n; ++i) {
    std::cin >> fence[i];
    right = std::max((int)right, fence[i]);
  }

  /* 二分主体 */
  double eps = 1e-5;
  while (right - left > eps) {
    double mid = (left + right) / 2;
//    DBG(mid);
    if (check(mid)) left = mid;
    else right = mid;
  }

  std::cout << (int)(right * 1000) << '\n';
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
