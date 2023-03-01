#include <stdio.h>
int main() {
  char ch;
  int i, j, n, k;
  while (scanf("%d %c", &n, &ch) && n != 0) {
    k = n / 2 + 1;
    for (int i = 0; i <= n / 2; i++) {
      for (int j = 1; j < k - i; j++) printf(" ");
      for (int j = k - i; j <= k + i; j++) printf("%c", ch);
      for (int j = k + i + 1; j <= n; j++) printf(" ");
      printf("\n");
    }
    for (int i = n / 2 - 1; i >= 0; i--) {
      for (int j = 1; j < k - i; j++) printf(" ");
      for (int j = k - i; j <= k + i; j++) printf("%c", ch);
      for (int j = k + i + 1; j <= n; j++) printf(" ");
      printf("\n");
    }
  }
  return 0;
}