// https://codeforces.com/problemsets/acmsguru/problem/99999/105
#include <stdio.h>

int main() {
  int sum = 0, n, m = 0;
  scanf("%d", &n);
  m = n / 3 * 2 + ((n % 3 == 2) ? 1 : 0);
  printf("%d", m);
  return 0;
}