#include <stdio.h>

int inverse(int n);

int main() {
  int n, start = 0;
  scanf("%d", &n);
  while (n != inverse(n)) {
    if (!start) {
      start = 1;
      printf("%d", n);
    }
    n += inverse(n);
    printf(" %d", n);
    }
  if (n < 10) printf("%d", n);
  return 0;
}

int inverse(int n) {
  int isum = 0;
  while (n) {
    isum = isum * 10 + n % 10;
    n /= 10;
  }
  return isum;
}