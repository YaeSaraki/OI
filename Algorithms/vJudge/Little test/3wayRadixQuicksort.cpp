/**
 * @problem:
 * @link:
 * @category:
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using namespace std;
using ll = long long;
using PI = pair<int, int>;

void quickSort(int arr[], const int length) {
  if (length <= 1) return;
  const int pivot = arr[rand() % length];
  int i = 0, j = 0, k = length;
  while (i < k) {
    if (arr[i] < pivot) swap(arr[i++], arr[j++]);
    else if (arr[i] > pivot) swap(arr[i], arr[--k]);
    else ++i;
  }
  quickSort(arr, j), quickSort(arr + k, length - k);
}

inline void solve() {}

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
