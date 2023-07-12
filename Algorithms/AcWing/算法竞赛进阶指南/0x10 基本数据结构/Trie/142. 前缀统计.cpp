/**
  * \link: https://www.acwing.com/problem/content/144/ 
  * \category: Trie 字典树
  * 
  *
  * \note: 
  **/
#include <algorithm>
#include <iostream>
#include <string>

// #define ONLINE_JUDGE
using namespace std;
using ll = long long;
using ull = unsigned long long;

int idx = 0;
const int kN = 1001001;
vector<int> cnt(kN); // store the substring sumNumber by idx.
vector<vector<int> > son(kN, vector<int> (26));

void Insert(string s) {
  int p = 0;
  for (auto it : s) {
    int u = it - 'a';
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
  }
  ++cnt[p]; 
}

int Query(string s) {
  int ans = 0, q = 0;
  for (auto it : s) {
    int u = it - 'a';
    q = son[q][u];
    if (q == 0) return ans;
    ans += cnt[q];
  }
  return ans;
}

inline void solve() {
   int n, q; cin >> n >> q;
   for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    Insert(s);
   }
   for (int i = 0; i < q; ++i) {
    string s; cin >> s;
    cout << Query(s) << '\n';
   }
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