#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n; cin >> n;
  char ch; cin >> ch;
  int sum = 1, t = 1;
  if (n == 0) {cout << "0"; return 0;}
  if (n < 7) { cout << ch << endl; cout << n - 1; return 0;}
  do {
    t += 2;
    sum += 2 * t;
  } while (sum + 2 * (t + 2) <= n);

  for (int i = 0; i <= t / 2; ++i) {
    for (int j = 1; j <= i; ++j) cout << " ";
    for (int j = 1; j <= t - 2 * i; ++j) cout << ch;
    cout << '\n';
  }
  for (int i = t / 2 - 1; i >= 0; --i) {
    for (int j = 1; j <= i; ++j) cout << " ";
    for (int j = 1; j <= t - 2 * i; ++j) cout << ch;
    cout << '\n';
  }
  cout << n - sum << endl;
  return 0;
}