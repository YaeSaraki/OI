#include <math.h>
#include <stdio.h>

int main() {
  long long sum = 0;
  int n, t;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    sum += t;
    while (sum >= 10000) sum %= 10000;
  }
  if (sum % 2 == 0)
    printf("ZJX");
  else
    printf("ZH");
  return 0;
}