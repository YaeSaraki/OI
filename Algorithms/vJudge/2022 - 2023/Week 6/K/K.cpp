#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int v[4] = {0, 28, 25, 20};
int w[4] = {0, 75, 50, 30};

int f[4][20010];

string res[4] = {"", "85:", "75:", "65:"};
int main() {
  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 0; k * v[i] <= j && k <= j / v[i]; ++k) {
        f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
      }
    }
  }
  int cur = f[3][n];
  
  for (int i = 3; i >= 1; --i) {
    int flag = 0;
    for (int j = n; j >= 0; --j) {
      for (int k = 0; k * v[i] <= j && k <= j / v[i]; ++k) {
        if (cur == f[i - 1][j - v[i] * k] + w[i] * k) {
          cur -= w[i] * k;
          mp[i] = k;
          flag = 1;
          break;
        }
      }
      if (flag == 1) break;
    }
  }

  for (int i = 1; i <= 3; ++i) cout << res[i] << mp[i] << "\n";
  
  return 0;
}