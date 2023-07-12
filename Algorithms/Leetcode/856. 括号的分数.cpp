/**
 * \link: https://leetcode.cn/problems/score-of-parentheses/
 * \category: string stack
 * 
 * 
 * 
 **/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

/** using Stack to solve */
class Solution {
 public:
  int scoreOfParentheses(string s) {
    stack<int> stk;
    stk.push(0);
    for (char ch : s) {
      if (ch == '(') stk.push(0);
      else {
        int value = stk.top();
        stk.pop();
        stk.top() += max(value * 2, 1);
      }
    }
    return stk.top();
  }
};

/** calculate the balance of () to solve */
class Solution2 {
  public:
    int scoreOfParentheses(string s) {
      int bal = 0, res = 0;
      for (int i = 0; i < s.length(); ++i) {
        bal += (s[i] == '(' ? 1 : -1);
        if (s[i] == ')' && s[i - 1] == '(')
          res += 1 << bal;
      }
      return res;
    }
};

string stringToString(string input) {
  assert(input.length() >= 2);
  string result;
  for (int i = 1; i < input.length() - 1; i++) {
    char currentChar = input[i];
    if (input[i] == '\\') {
      char nextChar = input[i + 1];
      switch (nextChar) {
        case '\"':
          result.push_back('\"');
          break;
        case '/':
          result.push_back('/');
          break;
        case '\\':
          result.push_back('\\');
          break;
        case 'b':
          result.push_back('\b');
          break;
        case 'f':
          result.push_back('\f');
          break;
        case 'r':
          result.push_back('\r');
          break;
        case 'n':
          result.push_back('\n');
          break;
        case 't':
          result.push_back('\t');
          break;
        default:
          break;
      }
      i++;
    } else {
      result.push_back(currentChar);
    }
  }
  return result;
}

int main() {
  string line;
  while (getline(cin, line)) {
    string s = stringToString(line);

    int ret = Solution().scoreOfParentheses(s);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}