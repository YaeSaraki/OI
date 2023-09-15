/**
 * \link: https://vjudge.csgrandeur.cn/problem/HDU-6577
 * \category: 签到
 * 
 * 
 * 
*/
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  int x, y; while(cin >> x >> y) {
    int a = (x + y) / 2;
    int b = x - a;
    cout << a * b << '\n';
  }
  return 0;
}