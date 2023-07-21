/**
 * @problem: P1120 小木棍
 * @link: https://www.luogu.com.cn/problem/P1120
 * @category: DFS 剪枝
 * @date: Thu Jul 20 12:40:30 CST 2023
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

#define DBG(x) cout << #x << " = " << (x) << '\n'

using namespace std;
using ll = long long;
using PI = pair<int, int>;

constexpr int kN = 64;

int n, length, sum;
array<int, kN> sticks;
array<bool, kN> vis;
array<int, kN> ne;

/** u表示拼好的木棍，cur表示目前所拼木棍的长度，start表示遍历木棍的下标，用于下一次的拼装检查。 */
bool DFS(int u, int cur, int start) {
  /** 如果所有木棒都拼好了，则满足题意，返回true。 */
  if (u * length == sum) return true;
  /** 如果目前木棍拼好了，则开始 DFS，拼装下一根木棍 */
  if (cur == length) return DFS(u + 1, 0, 0);

  /** 优化: 二分查找下一根满足条件的小木棒。 */
  int left = start, right = n - 1, mid;
  while (left < right) {
    mid = (left + right) >> 1;
    if (sticks.at(mid) > length - cur) left = mid + 1;
    else right = mid;
  }

  /** 枚举 拼装 DFS： 从大到小枚举每一根小木棒，进行拼装步骤。*/
  for (int i = left; i < n; ++i) {
    int l = sticks.at(i);
    /** 拼装检查： 如果该小木棒用过了，则跳过。
     *           如果该小木棍太长了，则跳过。 */
    if (vis.at(i) || cur + l > length) continue;

    /** 至此，该小木棍可以拼装，DFS拼装下一段。 */
    vis.at(i) = true;
    if (DFS(u, cur + l, i + 1)) return true;
    vis.at(i) = false;

    /**
     * 至此，说明该小木棍拼装后，后续没有DFS出满足条件的解，可进行以下3处剪枝：
     * 1. 如果目前所拼木棍的长度为0，但拼装第一根小木棒后后续拼装却失败了，说明这根小木棒(第一根)在哪里都无法拼装出满足条件的木棍，因此返回false。
     * 2. 如果目前所拼木棍的长度加上该小木棒后为满足条件的木棍，但拼装后后续拼装却失败了，说明DFS过程中无法拼出后续木棍，因此直接返回false。
     * 3. 如果该小木棒拼装后后续拼装失败，那么与该小木棒同长的其他小木棒也会拼装失败(反证法)，因此遍历时直接跳过。
     **/
    if (cur == 0) return false;
    if (cur + l == length) return false;
    i = ne[i];
  }
  return false;
}

inline void solve() {
  length = 0, sum = 0;
  cin >> n;
  int k = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x > 50) continue;
    sum += x;
    sticks.at(k++) = x;
    length = max(length, x);
  }

  n = k;
  sort(sticks.begin(), next(sticks.begin(), k), greater());

  /** 构建ne数组，用于跳过相同长度的小木棒。 */
  ne[n - 1] = n - 1;
  for (int i = n - 2; ~i; --i) {
    if (sticks[i] == sticks[i + 1]) {
      ne[i] = ne[i + 1];
    } else {
      ne[i] = i;
    }
  }

  while (length <= sum) {
    if (sum % length == 0 && DFS(0, 0, 0)) {
      cout << length << "\n";
      break;
    }
    ++length;
  }
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
