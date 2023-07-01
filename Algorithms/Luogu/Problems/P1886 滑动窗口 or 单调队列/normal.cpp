/**
 * https://www.luogu.com.cn/problem/P1886
 * \category: 滑动窗口 单调队列
 * 模板
 * 
 * 
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int kN = 1001001;
int a[kN], q[kN];

int main() {
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int h = 1, t = 0;
  for (int i = 1; i <= n; ++i) {
    while (h <= t && a[q[t]] >= a[i]) --t;
    q[++t] = i;
    if (q[h] < i - k + 1) ++h;
    if (i >= k) cout << a[q[h]] << " ";
  }
  puts("");
  h = 1, t = 0;
  for (int i = 0; i <= n; ++i) {
    while (h <= t && a[q[t]] <= a[i]) --t;
    q[++t] = i;
    if (q[h] < i - k + 1) ++h;
    if (i >= k) cout << a[q[h]] << " ";
  }

  return 0;
}