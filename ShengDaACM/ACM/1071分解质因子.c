#include <stdio.h>
int main() {
  int n;
  int i = 2;
  scanf("%d", &n);
  while (n != 1) {
    while (n % i == 0) {
      printf("%d", i);
      if (n != i) printf(" ");
      n /= i;
      i = 2;
    }
    i++;
  }
  return 0;
}
