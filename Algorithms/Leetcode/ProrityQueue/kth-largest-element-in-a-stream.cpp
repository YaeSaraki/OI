/**
 * @problem: 703. 数据流中的第 K 大元素
 * @link: https://leetcode.cn/problems/kth-largest-element-in-a-stream
 * @category: heap priority queue
 * @date: Fri Jul 14 13:36:16 CST 2023
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/** using priority_queue. */
class KthLargest {
 public:
  priority_queue<int, vector<int>, greater<> > que;
  int k;
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for (auto it : nums) add(it);
  }

  int add(int val) {
    que.push(val);
    if (que.size() > k) que.pop();
    return que.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 **/
