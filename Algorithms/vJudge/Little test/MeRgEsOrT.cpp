#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) cout << #x << " = " << (x) << '\n'
//#define int long long

using namespace std;
using ll = long long;
using PI = pair<int, int>;
#define int long long
const int kN = 2e5 + 233;
int a[kN];

void merge(const int *a, size_t a_len, const int *b, size_t b_len, int *c) {
  size_t i = 0, j = 0, k = 0;
  /** 必须先判断b[j] < a[i], 保证其稳定性 */
  while (i < a_len && j < b_len) c[k++] = (b[j] < a[i] ? b[j++] : a[i++]);
  while (i < a_len) c[k++] = a[i++];
  while (j < b_len) c[k++] = b[j++];
}

void mergeSort(int *a, int left, int right) {
  if (right - left <= 1) return;
  int mid = (left + ((right - left) >> 1));
  mergeSort(a, left, mid), mergeSort(a, mid, right);
  int temp[kN];
  merge(a + left, mid - left, a + mid, right - mid, temp + left);
  // merge(a + left, a + mid, a + mid, a + right, temp + left) C++ Alogirithm
  for (int i = left; i < right; ++i) a[i] = temp[i];
}

inline void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  mergeSort(a, 0, n);
  // stable_sort(a.begin(), a.end()); C++ STL
  for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
  return;
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
