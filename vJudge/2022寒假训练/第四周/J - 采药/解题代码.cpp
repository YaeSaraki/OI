#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2002;
int a[N][N], t[N], v[N];

int main() {
  int T, M;
  cin >> T >> M;
  for (int i = 1; i <= M; ++i) cin >> t[i] >> v[i];
  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= T; ++j) {
      if (j >= t[i])
        a[i][j] = max(a[i - 1][j], a[i - 1][j - t[i]] + v[i]);
      else
        a[i][j] = a[i - 1][j];
    }
  }
  cout << a[M][T] << endl;
  return 0;
}