#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

/** stack */
class Solution {
 public:
  int longestValidParentheses(string s) {
    int ans = 0;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        stk.pop();
        if (stk.empty()) stk.push(i);
        else ans = max(ans, i - stk.top());
      }
    }
    return ans;
  }
};
