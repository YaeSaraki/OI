#include <math.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int upperBound(int left, int right, int value);

int main() {
  int n, m;
  cin >> n >> m;
  a.reserve(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.begin() + n);
  while (m--) {
    int t;
    cin >> t;
    int temp = upperBound(0, n - 1, t); 
    if (temp != -1) cout << a[temp] << endl;
    else cout << "-1" << endl;
  }
  return 0;
}

int upperBound(int left, int right, int value) {
  if (value >= a[right]) return -1;
  if (value < a[left]) return left;
  while (left <= right) {
    int middle = left + ((right - left) >> 1);    
    if (value >= a[middle]) left = middle + 1;
    else right = middle - 1;
  }
  return left;
}
