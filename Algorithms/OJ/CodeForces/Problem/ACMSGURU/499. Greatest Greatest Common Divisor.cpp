#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  bool a[1000001] = {0};
  int T, n, max_num = -1;
  cin >> T;
  while (T--) {
    cin >> n;
    a[n] = 1;
    max_num = max(max_num, n);
  }
  int out, temp;
  for (int i = 2; i <= max_num; i++) {
    temp = 0;
    for (int j = i; j <= max_num; j += i) {
      temp += a[j];
      if (temp > 1) {
        out = i;
        break;
      }
    }
  }
  cout << out << endl;
  return 0;
}