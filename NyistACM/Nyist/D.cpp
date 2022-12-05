#include <bits/stdc++.h>
#define M 100100100
using namespace std;

bool a[100100100];

int main() {
  int x = M;
  for (int i = 1; i <= x; i++)
    for (int j = i; j <= x; j++)
      for (int l = j; l <= x; l++) {
        if (i * i + j * j == l * l) {
          a[i] = 1, a[j] = 1, a[l] = 1;
        }
      }
  int T;
  cin >> T;
  while (T--) {
    int n, sum = 0, flag = 0, t;
    cin >> n;
    for (int i = 1; i <= M; i++) {
      if (a[i] == 0) sum++;
      if (sum == n) {
        t = i;
        flag = 1;
        break;
      }
    }
    if (flag && t <= 100000000)
      cout << t << endl;
    else
      cout << "shenmegouba" << endl;
  }
  return 0;
}