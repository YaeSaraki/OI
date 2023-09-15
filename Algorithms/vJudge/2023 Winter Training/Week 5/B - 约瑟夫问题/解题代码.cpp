#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;
using ll = long long;

#define cin fin
// #define cout fout
ifstream fin("test.in", ios::in);
ofstream fout("test.out", ios::out);

struct Node {
  int data;
  Node *next;
};
Node *head, *ptr, *tail, *temp;

int main() {
  int m, n; 
  cin >> m >> n;
  
  head = new Node; //创建链表
  head->next = nullptr;
  tail = head;

  for (int i = 1; i <= m; ++i) {  // 读入数据 构造环
    ptr = new Node;
    ptr->data = i;
    tail->next = ptr;
    tail = ptr;
  }
  ptr = head->next;
  tail->next = head->next;

  for (int i = 1; i <= m; ++i) {  // 约瑟夫环
    for (int j = 1; j < n; ++j) {
      temp = ptr;
      ptr = ptr->next;
    }
    cout << ptr->data << " ";
    temp->next = ptr->next;
    free(ptr);
    ptr = temp->next;
  }

  return 0;
}