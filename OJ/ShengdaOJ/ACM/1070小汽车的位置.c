#include <stdio.h>
int main() {
  int x = 0, y = 0, time = 0;
  int t;
  int turn = 0;
  int Direction = 2;
  while (turn != 3) {
    scanf("%d", &t);
    time = t - time;
    switch (Direction) {
      case 1:
        x += time * 10;
        break;
      case 2:
        y += time * 10;
        break;
      case 3:
        x -= time * 10;
        break;
      case 4:
        y -= time * 10;
        break;
    }
    time = t;
    scanf("%d", &turn);
    if (turn == 1)
      Direction++;
    else if (turn == 2)
      Direction--;

    if (Direction == 5)
      Direction = 1;
    else if (Direction == 0)
      Direction = 4;
  }
  printf("%d %d", x, y);
  return 0;
}