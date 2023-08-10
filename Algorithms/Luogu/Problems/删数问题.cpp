/**
 * @problem: P1106 删数问题
 * @link: https://www.luogu.com.cn/problem/P1106
 * @category: stirng greedy
 * @date:
 * @Author: YaeSaraki
 **/
#include <algorithm>
#include <iostream>
#include <string>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define long int
//#define int long long
using ll = long long;
using PI = std::pair<int, int>;

inline void solve() {
  std::string nums; std::cin >> nums;
  int k; std::cin >> k;

  while (k--) {
		/** 查找从高位开始最大的数，删除它. */
		for (int i = 0; i < nums.size(); ++i) {
		 	/* 1. 如果第二个位置为0， 那么删除第一个位置是最优的. */
      if (i == 0 && nums[1] == '0') {
        int zero = 1;
        i = 2;
        while (i + 1 < nums.size() && nums[i] == '0') ++zero, ++i;
        nums.erase(0, 1 + zero);
        break;
      }
			/* 2. 如果遍历到最后一位和倒数第二位，那么删除较大的数是最优的. */
      if (i == nums.size() - 2) {
        nums.erase(std::max_element(nums.end() - 2, nums.end()));
        break;
      }

      if (nums[i] > nums[i + 1]) {
        nums.erase(i, 1);
        break;
      }
    }
  }
  while (nums[0] == '0') nums.erase(0, 1);
  std::cout << (nums == std::string("") ? std::string("0") : nums)<< '\n';
}

bool rt = false;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
