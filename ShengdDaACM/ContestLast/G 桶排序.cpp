#include <stdio.h>

#include <iostream>
using namespace std;

int a[1011];
int main() {
  int n, t;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> t;
    a[t]++;
  }
  for (int i = 1011; i >= 0; i--) {
    while (a[i]) {
      cout << i << " ";
      a[i]--;
    }
  }
  return 0;
}