/**
 * @problem: P1352 没有上司的舞会
 * @link: https://www.luogu.com.cn/problem/P1352
 * @category: 动态规划,dp 搜索 树形数据结构 记忆化搜索
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <stack>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using namespace std;
using ll = long long;
using PI = pair<int, int>;

const int kN = 6e3 + 233;

int n;

vector<int> connection[kN];
vector<bool> isBranch(kN);
vector<int> happy_point(kN);
vector<vector<int> > dp(kN, vector<int> (2));

void DFS(int root) {
  for (int i = 0; i < connection[root].size(); ++i) {
    int next = connection[root][i];
    DFS(next);
    /**
     * dp[i][0] = max(dp[j][0], dp[j][1])
     * dp[i][1] = dp[j][0];
     **/
    dp[root][0] += max(dp[next][1], dp[next][0]);
    dp[root][1] += dp[next][0];
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> happy_point[i];
  for (int i = 0; i < n - 1; ++i) {
    int x, y; cin >> x >> y;
    connection[y].push_back(x);
    isBranch[x] = true;
  }


  int root = 0;
  for (int i = 1; i <= n; ++i) {
    if (!isBranch[i]) {
      root = i;
      break;
    }
  }

  for (int i = 1; i <= n; ++i) {
//  dp[i][0] = 0;
    dp[i][1] = happy_point[i];
  }

  DFS(root);

  cout << max(dp[root][0], dp[root][1]) << '\n';
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
