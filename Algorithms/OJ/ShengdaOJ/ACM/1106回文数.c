#include <stdio.h>

int inverse(int n);

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  int start = 0;
  for (int i = m; i <= n; i++) {
    if (i == inverse(i)) {
      if (start == 1) printf(" ");
      start = 1;
      printf("%d", i);
    }
  }
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