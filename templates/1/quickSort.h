#ifndef __mergeSort_H__
#define __mergeSort_H__

#ifndef _GLIBCXX_ALGORITHM
#include <algorithm>
#endif

#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

using namespace std;

void quickSort(int q[], int l, int r) {
  if (l >= r) return;
  int i = l, j = r, mid = q[l + r >> 1];
  while (i <= j) {
    while (q[i] < mid) ++i;
    while (q[j] < mid) --j;
    if (i <= j) swap(q[i], q[j]);
  }
  quickSort(q, l, j), quickSort(q, i, r); 
                                            //有两种情况吧；
                                            // 一种是 i 和 j 相等，此时a[i] 就是x，下一步 i 加1， j 减1，[l, j]就是左区间，[i, r]就是右区间。
                                            // 还有就是 i = j - 1，相当于把 i 和 j 与 a[i] 和 a[j] 一起交换，也是满足的。
}

#endif