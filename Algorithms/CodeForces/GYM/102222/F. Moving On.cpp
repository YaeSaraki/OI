/**
 * \link: https://codeforces.com/gym/102222/problem/F
 * \category: floyd  动态规划
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
#include <cstring>
#include <set>
//#define ONLINE_JUDGE

using namespace std;
using ll = long long;
const int kN = 233;

int rod = 1;
int n, q, s, e, w;
int r[kN], id[kN];
int dp[kN][kN][kN];

bool cmp(int a, int b) { return r[a] < r[b]; }

void Floyd() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j][k] = min(dp[i][j][k - 1], dp[i][id[k]][k - 1] + dp[id[k]][j][k - 1]);
      }
    }
  }
}

void inline solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> r[i], id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> dp[i][j][0];
	Floyd();
  cout << "Case #" << rod++ << ":\n";
  while (q--) {
    cin >> s >> e >> w;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (r[id[i]] <= w) ans = i;
    }
    cout << dp[s][e][ans] << '\n';
  }
  return ;
}

bool rt = true;
signed main() {
	cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
	if (rt) { int T; cin >> T; while (T--) solve() ;}
	else solve();
	return 0;
}