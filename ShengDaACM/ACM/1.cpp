#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll jieCheng(int n);

int main() {
  ll n = 50, sum = 0;
  for (int i = 1; i <= 50; i++) sum += jieCheng(i);
  cout << sum;
  return 0;
}

ll jieCheng(int n) {
  int sum = 1;
  for (int i = 1; i <= n; i++) sum *= i;
  return sum;
}