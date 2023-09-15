#include <iostream>
#include <algorithm>
using namespace std;
int a[100];

int main() {
  int n; 
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int average = sum / n;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != average) {
      ++cnt;
      if (a[i] > average) {
        a[i + 1] += a[i] - average; 
      } else {
        a[i + 1] -= average - a[i];
      }
    }
  }
  cout << cnt << endl;
}