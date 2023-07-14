/**
 * \link: https://ac.nowcoder.com/acm/contest/61132/J
 * \category: 暴力枚举
 *
 * \date:
 * \author: YaeSaraki
 **/

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

inline void solve() {
  int n; cin >> n;
  vector<int> vote(n);
  for (int i = 0; i < n; ++i) cin >> vote.at(i);
  sort(vote.begin(), vote.end());
  vector<int> tempScore(vote);
  tempScore.pop_back();
  double min_score = 0;
  for (auto it : tempScore) min_score += it;
  min_score = 1.0 * min_score / (n - 1);
  printf("%.6lf ", min_score);
  
  tempScore = vote;
  tempScore.erase(tempScore.begin());
  double max_score = 0;
  for (auto it : tempScore) max_score += it;
  max_score = 1.0 * max_score / (n - 1);
  printf("%.6lf\n", max_score);
  return;
}

/** compressed version. */
inline void solve2() {
  int n; cin >> n;
  vector<int> vote(n);
  for (int i = 0; i < n; ++i) cin >> vote.at(i);
  sort(vote.begin(), vote.end());
  int sum = 0;
  for (int num : vote) sum += num;
  double min_score = (double)(sum - *vote.rbegin()) / (n - 1);
  double max_score = (double)(sum - *vote.begin()) / (n - 1);
  printf("%.6lf %.6lf", min_score, max_score);
}

bool rt = false;
signed main() {
  // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}
