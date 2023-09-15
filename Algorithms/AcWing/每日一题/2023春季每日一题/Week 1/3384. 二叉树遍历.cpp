#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int k;
string str; 

void dfs() {
  if (str[k] == '#') { ++k; return; }
  char ch = str[k++]; // root treenode
  dfs(); // left child treenode
  cout << ch << " "; 
  dfs(); // right child treenode
}

int main() {
  cin >> str;
  dfs();
  return 0;
}