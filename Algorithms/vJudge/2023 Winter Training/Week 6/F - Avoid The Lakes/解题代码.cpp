#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>

using namespace std;

#define cin fin
#define cout fout
ifstream fin("test.in");
ofstream fout("test.out");

const int FARLANDS = 101;
int n, m;
int pockets, ans = INT_MIN;
bool grid[FARLANDS][FARLANDS], haspassed[FARLANDS][FARLANDS];
int direction[2][4] = {{1, 0, -1, 0}, {0, -1, 0, 1}};

void DepthFirstSearch(int x_now, int y_now);

int main() {
  cin >> n >> m;
  int T; cin >> T; while (T--) {
    int y, x;
    cin >> y >> x;
    grid[y][x] = true;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (grid[i][j]) {
        pockets = 1;
        haspassed[i][j] = true;
        DepthFirstSearch(j, i);
        ans = ans > pockets ? ans : pockets;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

void DepthFirstSearch(int x_now, int y_now) {
  for (int i = 0; i < 4; ++i) {
    int x_next = x_now + direction[0][i], y_next = y_now + direction[1][i];
    if ((0 < x_next && x_next <= m) && !haspassed[y_next][x_next] &&
        (0 < y_next && y_next <= n) && grid[y_next][x_next]) {
      ++pockets;
      haspassed[y_next][x_next] = true;
      DepthFirstSearch(x_next, y_next);
    }
  }
  return;
}