#include <math.h>
#include <cstdio>
#include <iostream>

int p[100100] = {0, 0, 1, 1, 0};
bool prime(int n);
int main() {
  int i = 6, T;
  while (i <= 100000) {
    p[i + 1] = prime(i + 1);
    p[i - 1] = prime(i - 1);
    i += 6;
  }
  scanf("%d", &T);
  int m, n, sum = 0;
  while (T--) {
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++)
      if (p[i]) {
        sum++;
        p[i] = 0;
      }
  }
  printf("%d", sum);
  return 0;
}

bool prime(int n) {
  int a = (int)sqrt(n + 1);
  for (int i = 2; i <= a; i++)
    if (n % i == 0) return 0;
  return 1;
}