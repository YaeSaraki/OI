#include <stdio.h>



int main() {
  char point;
  int m, n;
  while (~scanf("%c", &point)) {
    scanf("%d%d", &m, &n);
    char a[100][100] = {0};
    int Ox = m - 1, Oy = m - 1;
    for (int y = 0; y < m; y++) {
      for (int x = 0; x < m; x++) {
        if (x + y < m) {
          a[Oy - y][Ox - x] = '*';
          a[Oy - y][Oy + x] = '*';
        }
      }
    }
    for (int y = m; y < m + n; y++) {
      for (int x = m - n / 2 - 1; x < m + n / 2; x++) {
        a[y][x] = '*';
      }
    }
    if (point == 'u' || point == 'U') {
      for (int i = 0; i < m + n; i++) {
        for (int j = 0; j < 2 * m; j++) {
          if (a[i][j] == 0)
            printf(" ");
          else
            printf("%c", a[i][j]);
        }
        printf("\n");
      }
    }
    if (point == 'd' || point == 'D') {
      for (int i = m + n - 1; i >= 0; i--) {
        for (int j = 0; j < 2 * m; j++) {
          if (a[i][j] == 0)
            printf(" ");
          else
            printf("%c", a[i][j]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}