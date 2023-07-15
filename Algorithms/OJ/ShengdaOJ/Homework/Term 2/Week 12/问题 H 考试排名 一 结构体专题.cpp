#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int g;

struct student {
  string name;
  int score;
  bool operator<(const student &A) const {
    if (score != A.score) return score > A.score;
    if (name != A.name) return name < A.name;
    return false;
  }
  bool iswin() { return score >= g; }
} stu[101];

void inline solve() {
  int n, m; cin >> n >> m >> g;
  int pep = 0;
  vector<int> a(m + 1);
  for (int i = 1; i <= m; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    string name; cin >> stu[i].name;
    int x; cin >> x;
    for (int j = 0; j < x; ++j) {
      int t; cin >> t;
      stu[i].score += a[t];
    }
    if (stu[i].iswin()) ++pep;
  }
  sort(stu, stu + n);
  cout << pep << '\n';
  for (auto it : stu)
    if (it.score >= g) cout << it.name << " " << it.score << '\n';
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