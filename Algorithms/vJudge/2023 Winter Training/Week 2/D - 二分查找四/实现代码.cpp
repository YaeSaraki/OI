#include <math.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int upperBound(int left, int right, int value);
int lowerBound(int left, int right, int value);

int main() {
  int n, m;
  cin >> n >> m;
  a.reserve(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.begin() + n);
  while (m--) {
    int t, flag = 0;
    cin >> t;
    if (t > a[n - 1]) flag = 1;
    if (t < a[0]) flag = 1;
    if (flag) cout << "0" << endl;
    else  {
      int uB = upperBound(0, n - 1, t), lB = lowerBound(0, n - 1, t);
      cout << uB - lB << endl;
    }
  }
  return 0;
}

int upperBound(int left, int right, int value) {
  while (left <= right) {
    int middle = left + ((right - left) >> 1);    
    if (value >= a[middle]) left = middle + 1;
    else right = middle - 1;
  }
  return left;
}

int lowerBound(int left, int right, int value) {
  while (left <= right) {
    int middle = left + ((right - left) >> 1);    
    if (value > a[middle]) left = middle + 1;
    else right = middle - 1;
  }
  return left;
}
