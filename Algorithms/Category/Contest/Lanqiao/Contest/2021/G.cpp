#include <iostream>
#include <algorithm>

#define rep(i, a, b) for (int i = a; i <= b; ++i)

using namespace std;
using ll = long long;

const int N = 110, M = 1e+5 + 10;
int w[N];
bool f[N][M];

int main() {
  int n, m; cin >> n;
  rep(i, 1, n) cin >> w[i], m += w[i];
  rep(i, 1, n) rep(j, 1, m) {
    if (w[i] == j) f[i][j] = true;
    else f[i][j] = f[i - 1][j] | f[i - 1][abs(j - w[i]) | f[i - 1][j + w[i]]];
  }
  int ans = 0;
  rep(i, 1, m) {
    if (f[n][i]) ++ans;
  } 
  cout << ans << endl;
  return 0;
}