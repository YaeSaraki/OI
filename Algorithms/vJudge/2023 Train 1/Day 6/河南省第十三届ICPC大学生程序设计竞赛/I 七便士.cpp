/**
 * https://ac.nowcoder.com/acm/contest/17148/I
 * \category: 模拟 (DFS (记忆化搜索
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <bitset>

// #define ONLINE_JUDGE
using namespace std;

const int kN = 10010;
unordered_map<bitset<8>, int> mem;


int DFS(bitset<8> b) {
  if (mem.count(b)) return mem[b];
  if (b.count() == 7) return mem[b] = 1;

  for (int i = 0; i < 8; ++i) if (b[i] == 0) {
    for (int j = 0; j < 2; ++j) {
      int ne[2] = { (i + 3) % 8, (i + 5) % 8 };
      if (b[ne[j]] == 0) { b[ne[j]] = 1; if(DFS(b)) return mem[b] = 1; b[ne[j]] = 0; }
    }
  }
  return mem[b] = 0;
}

inline void solve() {
  bitset<8> b;
  mem.clear();
  for (int i = 0; i < 8; ++i) { char x; cin >> x; if (x == '1') b[i] = 1; }
  cout << (DFS(b) ? "Yes\n" : "No\n");
  return ;
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if(rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}