#include <math.h>
#include <stdio.h>

#define N 100

int n, a[N][N], ii, jj;

int BalanceMatrix();

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);

  int b = BalanceMatrix();

  if (b == 1)
    printf("OK");
  else if (b == 2)
    printf("Change bit(%d,%d)", ii, jj);
  else
    printf("Corrupt");
  return 0;
}

int BalanceMatrix() {
  int flag_j = 0, flag_i = 0;
  int sum, j, i;

  for (i = 0; i < n; i++) {
    for (sum = 0, j = 0; j < n; j++) sum += a[i][j];

    if (sum % 2 != 0) {
      flag_i++;
      ii = i;
    } else
      continue;
  }

  for (j = 0; j < n; j++) {
    for (sum = 0, i = 0; i < n; i++) sum += a[i][j];

    if (sum % 2 != 0) {
      flag_j++;
      jj = j;
    } else
      continue;
  }
  if (flag_j == 0 && flag_i == 0)
    return 1;
  else if (flag_j == 1 && flag_i == 1)
    return 2;
  else
    return -1;
}
