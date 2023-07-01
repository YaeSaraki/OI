#include <iostream>
#include <algorithm>
using namespace std;


int f[200200];
struct Data {
  int head, tail, val;
  bool operator<(const Data &A) const { return tail < A.tail; }
} holy[200200];

int My_lower_bound(int l, int r, int val) {
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (holy[mid].tail < val) ans = mid, l = mid + 1;
    else r = mid - 1;
  }
  return ans;
}

inline void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> holy[i].head >> holy[i].tail;
    holy[i].val = holy[i].tail - holy[i].head + 1;
  }
  sort(holy + 1, holy + n + 1);
  for (int i = 1; i <= n; ++i) f[i] = max(f[i - 1], f[My_lower_bound(1, i, holy[i].head)] + holy[i].val);
  return cout << f[n], void();
}

bool rt = false;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) {int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}