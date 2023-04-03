#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100100;
int a[MAXN], b[MAXN];
int n, k;

bool check(int mid) {
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += (a[i] / mid) * (b[i] / mid);
  if (ans >= k) return 1;
  return 0;
}

int main() {
  int ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]); 
    ans  = max(a[i], max(ans, b[i]));
  }
  int l = 0, r = ans * 2;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }
  cout << l << endl;
  return 0;
}