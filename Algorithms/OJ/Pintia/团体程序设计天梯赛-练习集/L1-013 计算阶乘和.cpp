#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n; cin >> n;
  if (n == 0) return cout << "0", 0;
  int cnt = 1, ans = 0;
  for (int i = 1; i <= n; ++i) cnt *= i, ans += cnt;
  cout << ans << endl;
  return 0; 
}