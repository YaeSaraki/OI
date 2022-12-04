#include <math.h>

#include <iostream>
using namespace std;
int main() {
  int win = 0;
  char a1, a2, a3, b1, b2, b3;
  scanf("%c %c %c\n", &a1, &a2, &a3);
  scanf("%c %c %c", &b1, &b2, &b3);
  if (a1 == 'A' && a2 == 'A' && a3 == 'A') win++;
  if (win)
    cout << "zh";
  else
    cout << "wyz";
  return 0;
}
