/**
 * @problem: 264. 丑数 II
 * @link: https://leetcode.cn/problems/ugly-number-ii/description/
 * @category: priority queue hash 动态规划
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;
using ll = long long;

/** using priority_queue */
class Solution {
public:
  int nthUglyNumber(int n) {
    vector<ll> factors = {2, 3, 5};
    priority_queue<ll, vector<ll>, greater<> > heap;
    unordered_set<ll> hashSet;
    heap.push(1);
    hashSet.insert(1);
    ll ugly_number = 0;
    for (int i = 0; i < n; ++i) {
      auto cur = heap.top(); heap.pop();
      ugly_number = cur;
      for (ll factor : factors) {
        ll next = cur * factor;
        if (!hashSet.count(next)) {
          heap.push(next);
          hashSet.insert(next);
        }
      }
    }
    return ugly_number;
  }
};