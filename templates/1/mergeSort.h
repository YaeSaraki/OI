#ifndef __mergeSort_H__
#define __mergeSort_H__

#ifndef _GLIBCXX_ALGORITHM
#include <algorithm>
#endif

#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

using namespace std;

const int MAXN = 233;

void mergeSort(int q[], int l, int r) {
  if (l >= r) return;
  int mid = (l + r) >> 1;
  mergeSort(q, l, mid);
  mergeSort(q, mid + 1, r);
  int tmp[MAXN];
  int k = 0, i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (q[i] <= q[j])
      tmp[k++] = q[i++];
    else
      tmp[k++] = q[j++];
  }
  while (i <= mid) tmp[k++] = q[i++];
  while (j <= r) tmp[k++] = q[j++];
  for (int i = l, j = 0; i <= r; ++i) q[i] = tmp[i];
}
#endif
