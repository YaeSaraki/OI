#include <algorithm>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

// #define cin fin
// #define cout fout
ifstream fin("test.in", ios::in);
ofstream fout("test.out", ios::out);

struct Node {
  int x, y, step;
  Node(int a, int b, int c) { x = a, y = b, step = c; };
};

int m, n, x_start, y_start;
char grid[23][23];
bool haspassed[23][23];
int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int BreadthFirstSearch();

int main() {
  cin >> m >> n;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == '@') x_start = j, y_start = i;
    }
  }
  cout << BreadthFirstSearch() << endl;
  return 0;
}

int BreadthFirstSearch() {
  queue<Node> queue;
  haspassed[y_start][x_start] = true;
  queue.push(Node(x_start, y_start, 0));
  while (!queue.empty()) {
    Node now = queue.front();
    queue.pop();
    if (grid[now.y][now.x] == '*') return now.step;
    for (int i = 0; i < 4; ++i) {
      int x = now.x + direction[i][0], y = now.y + direction[i][1],
          step = now.step + 1;
      if (x && y && x <= n && y <= m && grid[y][x] != '#' && !haspassed[y][x]) {
        haspassed[y][x] = true;
        queue.push(Node(x, y, step));
      }
    }
  }
  return -1;
}