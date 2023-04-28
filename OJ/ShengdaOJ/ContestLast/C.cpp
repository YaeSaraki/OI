#include <math.h>
#include <stdio.h>

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  m *= 1000;
  if (m % n != 0)
    printf("%d", m / n + 1);
  else
    printf("%d", m / n);
  return 0;
}