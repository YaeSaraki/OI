/**
 * \link: https://www.acwing.com/problem/content/90/
 * \category: 单调栈
 * 
 * 
 * 
*/
class MinStack {
 public:
  /** initialize your data structure here. */
  int t = 0, t_minstack = 0;
  int stack[233] = {0}, minstack[233] = {0x3F3F3F3F};
  MinStack() {}

  void push(int x) {
    stack[++t] = x;
    if (x <= minstack[t_minstack]) minstack[++t_minstack] = x;
  }

  void pop() {
    if (minstack[t_minstack] == stack[t]) --t_minstack;
    --t;
  }

  int top() { return stack[t]; }

  int getMin() { return minstack[t_minstack]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */