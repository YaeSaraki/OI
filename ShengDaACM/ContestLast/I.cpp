#include <math.h>
#include <stdio.h>

int FindPrime(int n) {
  int m = sqrt(n) + 1;
  for (int i = 2; i < m; i++) {
    if (n % i == 0) return 0;
  }
  int sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  if (sum % 5 == 0) return 1;
  return 0;
}

int main(void) {
  int n;

  while (scanf("%d", &n) != EOF) {
    if (FindPrime(n) == 1)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
