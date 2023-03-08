
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n; cin >> n;
  int m = 1, k = 0;
  int i;
  int flag = 1; // 为满足 Z 顺序 
  for (i = 0;;++i) { //第i排 分子分母和为i + 1
    m += k++;
    flag = - flag;
    if (m > n) break;
  }
  m -= k; //最后多加的要减一下
  int x = n - m; // 这里算出第i排多出的值x，即为分子分母对中的一个
  if (flag == -1) cout << x << "/" << i + 1 - x;
  else cout << i + 1 - x << "/" << x;
  return 0; 
}