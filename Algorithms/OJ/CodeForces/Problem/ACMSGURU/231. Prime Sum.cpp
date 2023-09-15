#include <math.h>

#include <iostream>
using namespace std;
bool p[1000000] = {0};
int m[100000] = {0}, o[50000] = {0}, sum = 0, num = 0;
void sift(int n);
int main() {
  int n;
  cin >> n;
  sift(n);
  for (int i = 1; i < sum; i++)
    if (!p[m[i] + 2]) o[num++] = m[i];
  cout << num << endl;
  for (int i = 0; i < num; i++) cout << 2 << " " << o[i] << endl;
  return 0;
}

void sift(int n) {
  for (int i = 2; i <= n; i++)
    if (!p[i]) {
      m[++sum] = i;
      for (int j = i + i; j <= n; j += i) p[j] = 1;
    }
}
