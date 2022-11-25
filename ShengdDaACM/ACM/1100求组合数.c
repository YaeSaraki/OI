#include <stdio.h>

long fact(long n);

int main() {
  int m, k;
  scanf("%d%d", &m, &k);
  printf("%ld", fact(m) / (fact(k) * fact(m - k)));
  return 0;
}

long fact(long n) {
  long sum = 1;
  while (n) {
    sum *= n;
    n--;
  }
  return sum;
}