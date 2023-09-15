#include <iostream>
using namespace std;

int main() {
  for (int i = 0; i <= 100; ++i) {
    int sum = 0;
    for (int j = i; j <= 100; ++j) {
      sum += j;
      if (sum == 236) {
        cout << i << endl;
        return 0;
      }
    }
  }
  return -1;
}