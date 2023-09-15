#include <cmath>
#include <iostream>
using namespace std;

int gp = 0;
char ch[100100] = {0};
void GamePoints(int n);

int main() {
  while (cin >> ch[gp], ch[gp++] != 'E') continue;
  GamePoints(11);
  cout << endl;
  GamePoints(21);
}

void GamePoints(int n) {
  int a = 0, b = 0;
  for (int i = 0; i < gp; i++) {
    if (ch[i] == 'W') a++;
    if (ch[i] == 'L') b++;
    if (abs(a - b) >= 2 && ((a >= n) || (b >= n))) {
      cout << a << ":" << b << endl;
      a = 0, b = 0;
    }
  }
  cout << a << ":" << b << endl;
}