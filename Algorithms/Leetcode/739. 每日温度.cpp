/**
 * \link: https://leetcode.cn/problems/daily-temperatures/ 
 * \category: 单调栈 array
 * 
 * 
 *
 **/
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/* using 单调栈 */
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    /** init. */
    stack<int> stk;
    int n = temperatures.size();
    vector<int> ans(n);

    /** postorder traveral. */
    for (int i = n - 1; ~i; --i) {
      int num = temperatures.at(i);
      while (!stk.empty() && num >= temperatures[stk.top()]) stk.pop();
      ans[i] = stk.empty() ? 0 : stk.top() - i;
      stk.push(i);
    }
 
    return ans;
  }
};

/* using 单调栈 */
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    /** init. */
    stack<int> stk;
    int n = temperatures.size();
    vector<int> ans(n);

    /** preorder traveral. */
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && temperatures.at(i) > temperatures.at(stk.top())) {
        ans.at(stk.top()) = i - stk.top();
        stk.pop();
      }
      stk.push(i);
    }

    return ans;
  }
};
