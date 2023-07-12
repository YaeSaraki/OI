/**
 * \link: https://leetcode.cn/problems/next-greater-element-i/
 * \category: 栈 数组 哈希表 单调栈
 * 
 * 
 * 
 **/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

/* using monotonic stack + preorder traversal. */
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    /** init */
    stack<int> stk;
    int l2 = nums2.size(), l1 = nums1.size();
    unordered_map<int, int> hashmap;

    /** preorder traversal. */
    for (int i = 0; i < l2; ++i) {
      while (!stk.empty() && nums2.at(i) > stk.top()) {
        hashmap[stk.top()] = nums2.at(i);
        stk.pop();
      }
      stk.push(nums2.at(i));
    }
    while (!stk.empty()) {
      hashmap[stk.top()] = -1;
      stk.pop();
    }

    /** search the ans of nums1. */
    vector<int> ans(nums1);
    for (int i = 0; i < l1; ++i) {
      int num = nums1.at(i);
      if (hashmap.count(num)) ans[i] = hashmap[num];
    }
    return ans;
  }
};

/** using monotonic stack + postorder traversal. */
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> stk;
    unordered_map<int, int> hashmap;
    /** postorder traversal. */
    for (int i = nums2.size() - 1; ~i; --i) {
      int num = nums2.at(i);
      while (!stk.empty() && num >= stk.top()) stk.pop();
      hashmap[num] = (stk.empty() ? -1 : stk.top()); 
      stk.push(num);
    }

    vector<int> ans(nums1.size());
    for (int i = 0; i < nums1.size(); ++i) {
      ans[i] = hashmap[nums1[i]];
    } 
    return ans;
  }
};
