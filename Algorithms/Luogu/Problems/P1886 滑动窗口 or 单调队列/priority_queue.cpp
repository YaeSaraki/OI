/**
 * \link: https://www.luogu.com.cn/problem/P1886
 * \category 滑动窗口 单调队列 priority_queue
 * \author: https://www.luogu.com.cn/blog/136601/solution-p1886
 * 
 * 
*/
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

const int kN = 1001001;
int a[kN], ans_max[kN], ans_min[kN];

struct Node1 {
  int sequence, value;
  bool operator <(const Node1 &A) const {
    if (value != A.value) return value < A.value;
    if (sequence != A.sequence) return sequence > A.sequence;
    return false;
  }
} q1_temp;
struct Node2 {
  int sequence, value;
  bool operator <(const Node2 &A) const {
    if (value != A.value) return value > A.value;
    if (sequence != A.sequence) return sequence > A.sequence;
    return false;
  }
} q2_temp;

priority_queue<Node1> qu1;
priority_queue<Node2> qu2;

void inline solve() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) {
    q1_temp.sequence = i, q1_temp.value = a[i];
    q2_temp.sequence = i, q2_temp.value = a[i];
  //  cout << q2_temp.sequence << " " << q2_temp.value << '\n'; 
    qu1.push(q1_temp), qu2.push(q2_temp);
  }
  int top = 0;
  ans_max[top] = qu1.top().value, ans_min[top++] = qu2.top().value;
  for (int i = m; i < n; ++i) {
    q1_temp.sequence = i, q1_temp.value = a[i];
    q2_temp.sequence = i, q2_temp.value = a[i];
    qu1.push(q1_temp), qu2.push(q2_temp);
    while (i - qu1.top().sequence >= m) qu1.pop();
    while (i - qu2.top().sequence >= m) qu2.pop();
    ans_max[top] = qu1.top().value, ans_min[top++] = qu2.top().value;
  }
  for (int i = 0; i < top; ++i) cout << ans_min[i] << " ";
  cout << '\n';
  for (int i = 0; i < top; ++i) cout << ans_max[i] << " ";
  return ;
}

bool rt = false;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}