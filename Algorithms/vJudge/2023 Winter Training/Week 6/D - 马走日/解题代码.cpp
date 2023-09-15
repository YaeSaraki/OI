#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

#define cin fin
#define cout fout
ifstream fin("test.in", ios::in);
ofstream fout("test.out", ios::out);

const int FARLANDS = 20;

int n, m, x_start, y_start, ans, haveSolution; 
bool haspassed[FARLANDS][FARLANDS];
int x_nextstep[8] = {1, 1, -1, -1, 2, 2, -2, -2},
    y_nextstep[8] = {2, -2, 2, -2, 1, -1, 1, -1};
void DepthFirstSearch(int x_now, int y_now, int step);

int main() {
  int T; cin >> T; while (T--) {
    cin >> n >> m >> x_start >> y_start;
    ans = 0, haveSolution = n * m;
    memset(haspassed, 0, sizeof(haspassed));
    haspassed[y_start][x_start] = true;
    DepthFirstSearch(x_start, y_start, 1);
    cout << ans << endl;
  }
  return 0;
}

void DepthFirstSearch(int x_now, int y_now, int step) {
  if (haveSolution == step) {++ans; return;}
  for (int i = 0; i < 8; ++i) {
    int x_next = x_now + x_nextstep[i];
    int y_next = y_now + y_nextstep[i];
    if (x_next < 0 || n <= x_next ||
        y_next < 0 || m <= y_next) continue;
    if (haspassed[y_next][x_next]) continue;
    haspassed[y_next][x_next] = true;
    DepthFirstSearch(x_next, y_next, step + 1); //这里step + 1 不能写成++step！！！！！！
    haspassed[y_next][x_next] = false; 
  }
  return;
}