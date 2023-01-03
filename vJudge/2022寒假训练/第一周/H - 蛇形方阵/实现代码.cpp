#include <ctype.h>
#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;

int a[9][9] = {0};

int main() {
  int n; cin >> n;
  int x = -1, y = 0;
  for (int i = 1; i <= n * n;) {
    while (x + 1 < n && a[y][(x + 1)] == 0) {
      x++;
      a[y][x] = i++;
    }
    while (y + 1 < n && a[(y + 1)][x] == 0) {
      y++;
      a[y][x] = i++;
    }
    while (x - 1 >= 0 && a[y][(x - 1)] == 0) {
      x--;
      a[y][x] = i++;
    }
    while (y - 1 >= 0 && a[(y - 1)][x] == 0) {
      y--;
      a[y][x] = i++;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] != 0) {
        printf("%3d", a[i][j]);
      }
    }
    cout << endl;
  }
  return 0;
}