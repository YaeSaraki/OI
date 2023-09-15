#include <iostream>
#include <algorithm>
using namespace std;

bool judge(int num) {
  while (num) {
    if (num % 10 == 2 || num % 10 == 4) return false;
    num /= 10;
  }
  return true;
}

int main() {
  int i = 0, j = 0, k = 0, cnt = 0;
  for (int i = 1; i < 2019; ++i) 
    for (int j = 1; j < 2019; ++j) {
      k = 2019 - i - j;
      if (judge(i) && judge(j) && judge(k)) {
        if (i < j && j < k) ++cnt;
      }
    }
  cout << cnt << endl;
  return 0;
}