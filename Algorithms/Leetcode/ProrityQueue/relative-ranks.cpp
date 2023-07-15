/**
 * @problem: 506. 相对名次
 * @link: https://leetcode.cn/problems/relative-ranks/
 * @category: Array sort heap priority deque
 * @date: Fri Jul 14 11:12:59 CST 2023
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  const char kMedal[3][20] = {{"Gold Medal"},{"Silver Medal"},{"Bronze Medal"}};
  vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();
    vector<pair<int, int> > data(n);
    for (int i = 0; i < n; ++i) {
      auto &it = data[i];
      it.first = score[i];
      it.second = i;
    }
    sort(data.begin(), data.end());
    vector<string> ans(n);
    for (int i = 0; i < n; ++i) {
      int j = n - 1 - i;
      auto it = data[j];
      if (i < 3) ans[it.second] = kMedal[i];
      else ans[it.second] = to_string(i + 1);
    }
    return ans;
  }
};