#include <bits/stdc++.h>
#define N 100100
using namespace std;

char a[N], b[N];
int c[N + 1];

int main() {
  int temp = 0, up = 0, len_c = 0;
  fgets(a, N, stdin);
  fgets(b, N, stdin);
  int len_a = strlen(a) - 1;
  int len_b = strlen(b) - 1;
  reverse(a, a + len_a), reverse(b, b + len_b);
  int maxl = max(len_a, len_b);
  for (int i = 0; i <= maxl + 1; i++) {
    int ia = 0, ib = 0;
    if (i < len_a) ia = a[i] - '0';
    if (i < len_b) ib = b[i] - '0';
    temp = ia + ib + up;
    up = temp / 10;
    c[i] = temp % 10;
    len_c++;
  }
  int flag = 0;
  for (int i = len_c; i >= 0; i--) {
    if (!flag && c[i] != 0) flag = 1;
    if (flag) printf("%d", c[i]);
  }
  if (!flag) cout << 0;
  return 0;
}