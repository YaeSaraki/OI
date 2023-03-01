//Wrong Answer
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
using ll = long long;

#define cin fin
ifstream fin("test.in");

const int bow = 10, column = 10, sq = 10, num = 10;
int square[10][10];
bool bowHaveNum[bow][num], columnHaveNum[column][num], sqHaveNum[sq][num];
void DFS(int x, int y);
void Out();

int main() {
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      int t; 
      cin >> t;
      if (t) {
        square[i][j] = t;
        bowHaveNum[i][t] = columnHaveNum[j][t] =
            sqHaveNum[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][t] = true;
      }
    }
  }
  DFS(1, 1);
  cout << "No Solution" << endl;
  return 0;
}

void DFS(int x, int y) {
  if (square[y][x]) {
    if (x == 9 && y == 9)
      Out();
    else if (x == 9)
      DFS(1, y + 1);
    else
      DFS(x + 1, y);
  }
  else {
    for (int i = 1; i <= 9; ++i) {
      if (!bowHaveNum[y][i] && !columnHaveNum[x][i] &&
          !sqHaveNum[(y - 1) / 3 * 3 + (x - 1) / 3 + 1][i]) {
        square[y][x] = i;
        bowHaveNum[y][i] = columnHaveNum[x][i] =
            sqHaveNum[(y - 1) / 3 * 3 + (x - 1) / 3 + 1][i] = true;

        if (square[y][x]) {
          if (x == 9 && y == 9)
            Out();
          else if (x == 9)
            DFS(1, y + 1);
          else
            DFS(x + 1, y);
        }
        
        square[y][x] = 0;
        bowHaveNum[y][i] = columnHaveNum[x][i] =
            sqHaveNum[(y - 1) / 3 * 3 + (x - 1) / 3 + 1][i] = false;
      }
    }
  }
}

void Out() {
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (j != 1) cout << " ";
      cout << square[i][j];
    }
    cout << endl;
  }
  cout << endl;
  exit(0);
}