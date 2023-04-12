#include <algorithm>
#include <iostream>
using namespace std;

struct shop {
  double price;
  int num;
  bool operator<(const shop &a) const {
    if (price != a.price) return price < a.price;
    return false;
  }
} s[100];

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < n; ++i) cin >> s[i].price >> s[i].num;
  sort(s, s + n);

  double ans = 0;
  for (int i = 0; i < n && m; ++i) {
    int cnt = (m - s[i].num >= 0 ? s[i].num : m);
    m -= cnt, ans += cnt * s[i].price;
  }
  printf("%.2lf\n", ans);
  return 0;
}