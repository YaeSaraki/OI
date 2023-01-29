#include <math.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int binarySearch(int left, int right, int value);

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  a.reserve(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a.begin(), a.begin() + n);
  while (m--) {
    int t; scanf("%d", &t);
    if (binarySearch(0, n - 1, t) != -1) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}

int binarySearch(int left, int right, int value) {
  while (left <= right) {
    int middle = left + ((right - left) >> 1);
    if (value == a[middle]) return middle;
    if (value > a[middle]) left = middle + 1;
    if (value < a[middle]) right = middle - 1;
  }
  return -1;
}