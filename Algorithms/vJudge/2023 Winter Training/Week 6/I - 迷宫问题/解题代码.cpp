#include <algorithm>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

#define cin fin 
#define cout fout
ifstream fin("test.in");
ofstream fout("test.out");

int step = 0, step_min = INT_MAX;
int maze[5][5];
int direction[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
bool haspassed[5][5], ans[5][5];

void DFS(int x, int y);
void Print(int x, int y);

int main() {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> maze[i][j];
    }
  }
  haspassed[0][0] = true;
  DFS(0, 0);
  cout << "(0, 0)" << endl;
  ans[0][0] = false;
  Print(0,0);
  return 0;
}

void DFS(int x, int y) {
  if (x == 4 && y == 4) {
    if (step < step_min) {
      step_min = step;
      step = 0;
      for (int i = 0; i < 5; ++i) {
        for (int j = 0;j < 5; ++j) {
          ans[i][j] = haspassed[i][j];
        }
      }
    }
  }
  for (int i = 0; i < 4; ++i) {
    int x_next = x + direction[0][i], y_next = y + direction[1][i];
    if ((0 <= x_next && x_next < 5) && (0 <= y_next && y_next < 5) &&
        !haspassed[y_next][x_next] && !maze[y_next][x_next]) {
      ++step;
      haspassed[y_next][x_next] = true;
      DFS(x_next, y_next);
      haspassed[y_next][x_next] = false;
    }
  }
}

void Print(int x, int y) {
  for (int i = 0; i < 4; ++i) {
    int x_next = x + direction[0][i], y_next = y + direction[1][i];
    if ((0 <= x_next && x_next < 5) && (0 <= y_next && y_next < 5) &&
        ans[y_next][x_next]) {
      cout << "(" << y_next << ", " << x_next << ")" << endl;
      ans[y_next][x_next] = false;
      Print(x_next, y_next);
    }
  }
}