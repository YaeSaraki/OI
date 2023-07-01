#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1001;

int dp[N][N];
// int a[N][N];
int x;

int main() {
  int r; cin >> r;
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= i; ++j) {
      cin >> x;
      dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + x;
    }

  // for (int i = 1; i <= r; ++i)
  //   for (int j = 1; j <= r; ++j) {
  //     dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
  //   }

  int ans = 0;
  for (int i = 1; i <= r; ++i) ans = max(ans, dp[r][i]);
  cout << ans <<'\0';

  return 0;
}