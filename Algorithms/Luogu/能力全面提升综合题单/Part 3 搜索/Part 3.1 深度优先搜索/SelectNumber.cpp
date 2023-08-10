/**
 * @problem: P1036 [NOIP2002 普及组] 选数
 * @link: https://www.luogu.com.cn/problem/P1036
 * @category: DFS prime number
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using namespace std;
using ll = long long;
using PI = pair<int, int>;

const int kN = 2E7;
const int kUp = 2E4;
int n, m, ans;
int pri_size;
vector<int> nums;
array<int, kUp> prime;

bool isPrime(int x) {
  if (x < 2) return false;
  for (int i = 0; i < pri_size; ++i) {
    if (x % prime[i] == 0) return x == prime[i];
  }
  return true;
}

bool hasInit = false;
inline void Init() {
  if (hasInit) return;
  array<bool, kUp> vis{};
  for (int i = 2; i < kUp; ++i) {
    if (!vis[i]) prime[pri_size++] = i;
    for (int j = 0; j < pri_size; ++j) {
      if (1LL * i * prime[j] >= kUp) break;
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
  hasInit = true;
}

void DFS(int u, int ti, int sum) {
  if (ti == m && isPrime(sum)) return ++ans, void();

  for (int i = u; i < n; ++i) {
    DFS(i + 1, ti + 1, sum + nums[i]);
  }
}

inline void solve() {
  Init();
  cin >> n >> m;
  nums = vector<int> (n);
  for (int i = 0; i < n; ++i) cin >> nums[i];
  ans = 0;
  DFS(0, 0, 0);
  cout << ans << '\n';
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
