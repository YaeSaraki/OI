#include <iostream>
using namespace std;

char data[] = {"1023456789"};
int main() {
  int n;
  cin >> n;
  if (n > 10) {
    cout << "-1" << endl;
  } else {
    for (int i = 0; i < n; ++i) cout << data[i];
  }
  return 0;
}