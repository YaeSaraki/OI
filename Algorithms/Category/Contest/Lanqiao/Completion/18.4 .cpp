#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int dp[1001][4];

int main() {
  for (int n = 1; n <= 3; ++n) {
    for (int i = 1; i <= 1000; ++i) {
      dp[i][n] = dp[i - 1][n] + 1;
      for (int k = 1; k < i && n > 1; ++k)
        dp[i][n] = min(dp[i][n], max(dp[k - 1][n - 1], dp[i - k][n]) + 1);
    }
  }
  cout << dp[1000][3] << endl;
  return 0;
}