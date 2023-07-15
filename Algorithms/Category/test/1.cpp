#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int x; cin >> x;
  /** return the first 1 of the (bit)x */
  int the_first_one_of_the_bit_x = __builtin_ffs(x);
  cout << the_first_one_of_the_bit_x << '\n';
  int n = 5;
  int a[10] = {1, 2, 3 , 4 , 5 ,6 ,7, 8, 9};
  for (int i = 0; i < n; ++i) {
    cout << i + 1 << " \n"[i == n - 1];
  }

  return 0;
}