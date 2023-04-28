#include <iostream>
using namespace std;
int main() {
  char ch;
  while (cin >> ch, ch != '@') {
    int n;
    cin >> n;
    char a[1000][1000] = {{0}};
    int Ox = n - 1, Oy = 0;
    for (int x = 0; x <= n - 1; x++) {
      a[Oy + x][Ox + x] = ch;
      a[Oy + x][Ox - x] = ch;
    }
    for (int x = 0; x < 2 * n - 2; x++) a[n - 1][x] = ch;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n + i; j++) {
        if (a[i][j] == 0)
          cout << " ";
        else
          cout << a[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}