#include <stdio.h>

int inverse(int n);

int main() {
  int n, start = 0;
  scanf("%d", &n);
  while (n != inverse(n)) {
    if (start == 1) printf(" ");
    start = 1;
    printf("%d", n);
    n = n + inverse(n);
  }
  printf(" %d", n);
  return 0;
}

int inverse(int n) {
  int isum = 0;
  while (n != 0) {
    isum = isum * 10 + n % 10;
    n /= 10;
  }
  return isum;
}