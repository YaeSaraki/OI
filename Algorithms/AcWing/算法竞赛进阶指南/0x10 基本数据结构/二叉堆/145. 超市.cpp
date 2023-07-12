/**
  * \link: https://www.acwing.com/problem/content/147/
  * \category: 二叉堆 并查集 贪心
  * 
  *
  * \note: 
  **/
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <numeric>

// #define ONLINE_JUDGE
using namespace std;
using PI = pair<int, int>;

const int kN = 1e4 + 233;
array<int, kN> f;
vector<PI> a;
/** 并查集 */
int Find(int x) { return x == f[x] ? x : f[x] = Find(f[x]); } // ! 并查集注意 返回 f[x] = Find(f[x]) !

/** 贪心 + 并查集优化 */
inline void solve() {
  a.reserve(kN);
  int n; while (cin >> n) {
    a.clear();
    int time_max = 0;
    int input_value, input_time; 
    for (int i = 1; i <= n; ++i) {
      cin >> input_value >> input_time;
      a.push_back({-input_value, input_time});
      time_max = max(time_max, input_time);
    }
    sort(a.begin(), a.end());
    iota(f.begin(), next(f.begin(), time_max + 1), 0);
    int ans = 0;
    for (auto it : a) {
      input_value = -it.first, input_time = it.second;
      int pos = Find(input_time);
      if (pos) {
        ans += input_value;
        f[pos] = pos - 1;
      }
    }
    cout << ans << '\n';
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
