#include <math.h>

#include <cstring>
#include <iostream>
using namespace std;

bool prime(int n);

int main() {
  int T, n, a, flag;
  cin >> T;
  while (T--) {
    cin >> n;
    flag = 0;
    a = sqrt(n);
    for (int i = 2; i <= a; i++) {  //条件判断->flag
      if (prime(i))
        if (n % i == 0)
          if (prime(n / i)) {
            flag = 1;
            break;
          }
    }
    if (flag)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}

bool prime(int n) {
  int a = sqrt(n);
  if (n == 1) return false;
  for (int i = 2; i <= a; i++)
    if (n % i == 0) return false;
  return true;
}