#include <math.h>

#include <algorithm>
#include <iostream>

using namespace std;

string necklace;
int judge(int len);

int main() {
  cin >> necklace;
  int len = necklace.length();
  printf("%d", judge(len));
  return 0;
}

int judge(int len) {
  if (len % 2 != 0) return len;
  int flag = 1, templen = len / 2;
  for (int i = 0; i < templen; ++i) {
    if (necklace[templen - i - 1] != necklace[templen + i]) flag = 0;
  }
  if (flag == 0)
    return len;
  else
    return judge(len / 2);
}
