#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

// #define cin fin
// #define cout fout
ifstream fin("test.in", ios::in);
ofstream fout("test.out", ios::out);

char grid[233][233];
void DeterminePocketSize(int m, int n);

int main() {
  int m, n;
  while (cin >> m >> n && m && n) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> grid[i][j];
      }
    }
    int pockets = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '*') continue;
        if (grid[i][j] == '@') {
          pockets++;
          grid[i][j] = '*';
          DeterminePocketSize(i, j);
        }
      }
    }
    cout << pockets << endl;
  }
  return 0;
}

void DeterminePocketSize(int m, int n) {
  if (grid[m][n + 1] == '@') {
    grid[m][n + 1] = '*';
    DeterminePocketSize(m, n + 1);
  }
  if (grid[m + 1][n] == '@') {
    grid[m + 1][n] = '*';
    DeterminePocketSize(m + 1, n);
  }
  if (n && grid[m][n - 1] == '@') {
    grid[m][n + 1] = '*';
    DeterminePocketSize(m, n - 1);
  }
  if (m && grid[m - 1][n] == '@') {
    grid[m - 1][n] = '*';
    DeterminePocketSize(m - 1, n);
  }
  if (grid[m + 1][n + 1] == '@') {
    grid[m + 1][n + 1] = '*';
    DeterminePocketSize(m + 1, n + 1);
  }
  if (m && grid[m - 1][n + 1] == '@') {
    grid[m - 1][n + 1] = '*';
    DeterminePocketSize(m - 1, n + 1);
  }
  if (n && grid[m + 1][n - 1] == '@') {
    grid[m + 1][n - 1] = '*';
    DeterminePocketSize(m + 1, n - 1);
  }
  if (n && m && grid[m - 1][n - 1] == '@') {
    grid[m - 1][n - 1] = '*';
    DeterminePocketSize(m - 1, n - 1);
  }
}
