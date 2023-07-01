#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int floor = 0, cnt = 0;
  for (int i = 1; i <= 100; ++i) {
    floor += i;
    cnt += floor;
  }
  cout << cnt;
  return 0;
}