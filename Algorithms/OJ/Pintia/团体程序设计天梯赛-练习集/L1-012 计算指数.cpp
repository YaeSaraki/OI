#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int n; cin >> n;
  int ans = 1;
  ans <<= n;
  cout << 2 << "^" << n << " = " << ans << endl;
  return 0;
}