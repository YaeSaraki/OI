#include <iostream>
using namespace std;
const int N = 1010;
char str[N][5 * N];
int main(void) {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
  }
  int p;
  cin >> p;
  while (p--) {
    for (int i = 1; i <= 5; i++) {
      int q;
      scanf("%d", &q);
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int res = 1;
    for (int j = 1; j <= n; j++) {
      if (str[j][i] == '0') res = 0;
    }
    if (res) ans++;
  }
  cout << ans << endl;
  return 0;
}