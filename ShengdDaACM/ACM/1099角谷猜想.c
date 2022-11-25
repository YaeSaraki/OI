#include <math.h>
#include <stdio.h>

int main() {
  int n, step;
  while ((scanf("%d", &n)) != EOF) {
    step = 0;
    while (n != 1) {
      if (n % 2 == 0) {
        n /= 2;
        step++;
      } else {
        n = 3 * n + 1;
        step++;
      }
    }
    printf("%d\n", step);
  }

  return 0;
}