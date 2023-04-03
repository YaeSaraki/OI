#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100100;
int head, e[N], ne[N], idx;

void Init() { head = -1, idx = 0; }

void Add_to_head(int n) { //在头节点插入数据
  e[idx] = n;
  ne[idx] = head;
  head = idx++;
}
void Add(int k, int n) { //普通插入
  e[idx] = n;
  ne[idx] = ne[k];
  ne[k] = idx++;
}

int main() {

}