/**
  * \link: https://www.acwing.com/problem/content/139/ 
  * \category: 字符串 hash
  * 
  *
  * \note: 
  **/
#include <algorithm>
#include <array>
#include <iostream>
#include <string>

// #define ONLINE_JUDGE
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int kN = 1e6 + 233, kBase = 131;
int n;
string str;
array<ull, kN> h, p;

/** generate string hash and store in array h & p */
inline void Hash() {
  p[0] = 1;
  for (int i = 1; i <= n; ++i) {
    h[i] = h[i - 1] * kBase + str[i - 1] - 'a' + 1;
    p[i] = p[i - 1] * kBase;
  }
}

/** get the hash num */
ull get(int l,int r) {
  return h[r] - h[l - 1] * p[r - l + 1];
}

inline void solve() {
  cin >> str;
  n = str.length();
  Hash();
  int q; cin >> q; while (q--) {
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    // cout << get(l1, l2) << "\n";
    if (get(l1, r1) == get(l2, r2)) cout << "Yes\n";
    else cout << "No\n";
  }
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