#include <iostream>
using namespace std;

int a[40][40];

int main() {
  int n;
  cin >> n;
  int x = n / 2, y = 0;
  for (int i = 1; i <= n * n; i++) {
    a[y][x] = i;
    if (!a[(y - 1 + n) % n][(x + 1 + n) % n])
      x = (x + 1 + n) % n, y = (y - 1 + n) % n;
    else
      y = (y + 1 + n) % n;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
