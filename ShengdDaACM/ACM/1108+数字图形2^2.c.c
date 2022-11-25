#include <stdio.h>

int main() {
  int T;
  char ch;
  int n;
  while (scanf("%d %c", &n, &ch), n != 0) {
    int a[100][100] = {0};
    int O = n / 2;
    int x = 1, y = 1;
    for (int x = 0; x <= n / 2; x++)
      for (int y = 0; y <= n / 2; y++) {
        if (x + y <= O) {
          a[O + x][O + y] = 1;
          a[O - x][O + y] = 1;
          a[O + x][O - y] = 1;
          a[O - x][O - y] = 1;
        }
      }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == 1)
          printf("%c", ch);
        else
          printf(" ");
      }
      printf("\n");
    }
  }
  return 0;
}