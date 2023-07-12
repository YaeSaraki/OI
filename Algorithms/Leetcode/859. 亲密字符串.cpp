/**
 * \link: https://leetcode.cn/problems/buddy-strings/description/ 
 * \category: 
 *
 *
 *
 **/
#include <algorithm>
#include <iostream>
#include <array>
#include <string>
using namespace std;


class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    if (s.length() != goal.length()) return false;
    array<int, 26> alpha{0};
    int fst = -1, sec = -1;
    if (s == goal) {
      for (char elem : s)
        if (++alpha.at(elem - 'a') > 1) return true;
      return false;
    } else {
      for (int i = 0; i < s.length(); ++i) {
        if (s.at(i) != goal.at(i)) {
          if (fst == -1) fst = i;
          else if (sec == -1) sec = i;
          else return false;
        }
      }
    }
    if (sec != -1 && s.at(fst) == goal.at(sec) && s.at(sec) == goal.at(fst)) return true;
    else return false;
  }
};