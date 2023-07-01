#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int h, m;
  scanf("%d:%d", &h, &m);
  if (h < 12 || (h == 12 && m == 0)) return printf("Only %02d:%02d.  Too early to Dang.", h, m), 0;
  else {
    for (int i = 1; i <= h - 12 + (m == 0 ? 0 : 1); ++i) {
      printf("Dang");
    }
  }
  return 0;
}