#include <bits/stdc++.h>
using namespace std;

int a[1001], b[1001], c[1001], d[1001];

int main() {
  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  for (int i = 0; i < n; i++) scanf("%d", &d[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        for (int l = 0; l < n; l++) {
          if (a[i] + b[j] == c[k] + d[l]) sum++;
        }
  if (sum)
    cout << sum << endl;
  else
    cout << "all in" << endl;
  return 0;
}