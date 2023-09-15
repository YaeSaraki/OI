#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

#define cin fin
#define cout fout
ifstream fin("test.in", ios::in);
ofstream fout("test.out", ios::out);

const int FARLANDS = 8;
int n, k, step, ans;
char grid[FARLANDS][FARLANDS];
bool hasput[FARLANDS];
void DepthFirstSearch(int y_now);

int main () {
  while (cin >> n >> k && n != -1 && k != -1) {
    for (int i = 0; i < n; ++i) cin >> grid[i];
    ans = 0, step = 0;
    memset(hasput, 0, sizeof(hasput));
    DepthFirstSearch(0);
    cout << ans << endl;
  }  
}

void DepthFirstSearch(int y_now) {
  if (step == k) { ++ans; return; }
  if (y_now >= n) return;
  for (int i = 0; i < n; ++i) { // i ~ x 
    char now_position = grid[y_now][i];
    if (!hasput[i] && now_position == '#') {
      ++step;
      hasput[i] = true;
      DepthFirstSearch(y_now + 1);
      --step;
      hasput[i] = false;
    }
  }
  DepthFirstSearch(y_now + 1);
}
