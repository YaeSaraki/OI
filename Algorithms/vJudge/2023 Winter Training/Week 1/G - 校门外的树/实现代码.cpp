#include <ctype.h>
#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;

bool road[100100] = {0};

int main() {
  int u, v;
  int n; cin >> n;
  int m; cin >> m; while (m--) {
    cin >> u >> v;
    for (int i = u; i <= v; ++i) road[i] = 1;
  }
  int sum = 0;
  for (int i = 0; i <= n; ++i)
    if (road[i] == 0) sum++;
  cout << sum;
  return 0;
}