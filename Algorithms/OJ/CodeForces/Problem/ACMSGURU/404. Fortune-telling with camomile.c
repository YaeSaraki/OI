// https://codeforces.com/problemsets/acmsguru/problem/99999/404

#include <stdio.h>
#define N 101

int main() {
  char str[N][N];
  int result, m, n, i = 1;
  scanf("%d%d", &m, &n);
  getchar();
  for (int j = 1; j <= n; j++) {
    gets(str[i++]);
  }
  if (m % n == 0)
    puts(str[n]);
  else
    puts(str[(m % n)]);
  return 0;
}