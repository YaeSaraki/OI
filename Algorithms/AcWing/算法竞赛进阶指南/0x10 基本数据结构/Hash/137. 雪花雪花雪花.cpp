/**
  * \link: https://www.acwing.com/problem/content/139/ 
  * \category: 哈希表 字符串的最小表示法
  * 
  *
  * \note: 
  **/
#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <unordered_set>
// #define ONLINE_JUDGE
using namespace std;
using ll = long long;

const int kBase = 233;
const int kN = 1e5;

int m = 6, n;
array<array<int, 15>, kN> a, b;
array<int, kN> m1, m2; // 存储最小表示串下标
unordered_set<ll> s;

int GetMin(int *s) { // 字符串的最小表示法
  int i = 0, j = 1;
  while (i < m && j < m) {
    int k = 0;
    while (k < m && s[i + k] == s[j + k]) ++k;
    if (k == m) break;
    if (s[i + k] > s[j + k]) i += k + 1;
    else j += k + 1;
    if (i == j) ++j;
  }
  return min(i, j);
}

inline void solve() {
  cin >> n;
  /** input the data */
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      a[i][j + m] = a[i][j];
    }
  }
  b = a;
  /** get MinExpr: m1(positive path) & m2(negotive path) */
  for (int i = 0; i < n; ++i) m1[i] = GetMin(a[i].data());
  for (int i = 0; i < n; ++i) {
    reverse(b[i].begin(), next(b[i].begin(), 2 * m));
    m2[i] = GetMin(b[i].data());
  }
  /** Hash on MinExpr */
  bool flag = false;
  for (int i = 0; i < n; ++i) {
    ll h1 = 0, h2 = 0;
    for (int j = 0; j < m; ++j) {
      h1 = h1 * kBase + a[i][j + m1[i]];
      h2 = h2 * kBase + b[i][j + m2[i]];
    }
    if (!s.count(h1)) s.insert(h1);
    else { flag = true; break; }
    if (h1 == h2) continue;
    if (!s.count(h2)) s.insert(h2);
    else { flag = true; break; }
  }
  cout << (flag ? "Twin snowflakes found.\n" : "No two snowflakes are alike.\n");
  return ;
}

bool rt = false;
 int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return (0 ^ 0);
 }