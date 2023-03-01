#ifndef __mergeSort_H__
#define __mergeSort_H__

#ifndef _GLIBCXX_ALGORITHM
#include <algorithm>
#endif

#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

using namespace std;

bool check(int x){/* ... */} // 检查x是否满足某种性质
int binarySearch_1(int l, int r) { //整数二分查找,区间被分为[l, mid]和[mid + 1, r]时使用
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  return l;
}

#endif