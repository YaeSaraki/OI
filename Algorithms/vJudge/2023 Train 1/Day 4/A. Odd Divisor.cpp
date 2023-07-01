/**
 * https://codeforces.com/problemset/problem/1475/A
 * \category: 数学 定理
 * 
 * 
 *
*/
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

inline void solve() {
  ll n; cin >> n; // 数据很大 需要long long存
  if (n & (n - 1)) cout << "YES\n";
  else cout << "NO\n";
  return ;
}

bool rt = true;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}

/* 
todo 解题思路
*: 如果一个数有大于1的奇数因子，则必存在大于1的奇数质因子，因为 奇数=奇数*奇数
*: 如果一个数n没有大于1的奇数因子，意味着它只有偶数因子，但是大于1的偶数质数只有2，故除非n是2的m（m>=1）c次幂，否则一定存在大于1的奇数因子
new: n 是 2 的幂可以二进制表示为 n & （n - 1）= 0
*/