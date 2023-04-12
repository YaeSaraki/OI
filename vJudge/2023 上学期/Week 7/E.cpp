#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
using PII = pair<int, int>;
using ll = long long;

const int N = 100100;

int f[N], g[N];

void check(int m, int f[]) {
  set<PII> b;
  for (int i = 1; i <= m; ++i) {
    int l, r; cin >> l >> r;
    b.insert({l, r});
  }
  for (int i = 1; i <= m; ++i) {
    auto it = b.begin();
    while (it != b.end()) {
      ++f[i];
      int r = it->second;
      b.erase(it);
      it = b.upper_bound({r, -1});
    }
  }
}

int main() {
  int n, m1, m2;cin >> n >> m1 >> m2;
  
  check(m1, f), check(m2, g);

  for (int i = 1; i <= n; ++i) f[i] += f[i - 1];
  for (int i = 1; i <= n; ++i) g[i] += g[i - 1];

  int ans = 0;
  for (int i = 0; i <= n; ++i) ans = max(ans, f[i] + g[n - i]);
  
  cout << ans;
}