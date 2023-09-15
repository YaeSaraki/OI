#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Starr {
  double x, y;
};

vector<Starr> star;
vector<int> a(1);

bool isparallel(Starr &A, Starr &B, Starr &C) {
  return !((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}

void inline solve() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    double x, y; cin >> x >> y;
    star.push_back({x, y});
  }
  if (star.size() == 1) return cout << "1\n", void();
  if (star.size() == 2) return cout << "2\n", void();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (isparallel(star[i], star[j], star[k])) ++a[a.size() - 1];
      }
      a.push_back(0);
    }
  }
  return cout << *max_element(a.begin(), a.end()) << '\n', void();
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
}