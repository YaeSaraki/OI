// https://www.acwing.com/problem/content/3959/
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
using ll = long long;

// #define cin fin
// ifstream fin("test.in");

const int MAXN = 100100;
int prefixSum[MAXN];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> prefixSum[i];
    prefixSum[i] += prefixSum[i - 1];
  }
  int average = prefixSum[n] / 3;
  if (prefixSum[n] % 3 || n < 3) { cout << "0"; return 0; }
  ll ans = 0;
  for (int i = 2, separateTime = 0; i < n; ++i) {
    if (prefixSum[i - 1] == average) ++separateTime;
    if (prefixSum[i] == average * 2) ans += separateTime;
  }
  cout << ans << endl;
  return 0;
}