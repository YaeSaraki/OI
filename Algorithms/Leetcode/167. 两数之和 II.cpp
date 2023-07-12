/**
 * \link: https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
 * \category: array 双指针 
 *
 *
 *
 **/
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int l = 0, r = n - 1;
    while (l < n) {
      int sum = numbers.at(l) + numbers.at(r);
      if (sum < target) ++l;
      else if (sum > target) --r;
      else return vector<int> {l + 1, r + 1};
    }
    return {};
  }
};
