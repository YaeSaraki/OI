#include <algorithm>
#include <iostream>

typedef struct treeNode {
  char data;         // analysis CHAR
  treeNode* LChild;  // left child
  treeNode* RChild;  // right child
} treeNode;

// 1.Creat tree
treeNode* creatNewTreeNode(char data);
// 2.connect tree
void insertTreeNode(treeNode* curTreeNode, treeNode* LChild, treeNode* RChild);
// 3.ergodic tree


int main() {
  // 创建节点
  treeNode* A = creatNewTreeNode('A');
  if (A == NULL) return -1;
  treeNode* B = creatNewTreeNode('B');
  if (B == NULL) return -1;
  treeNode* C = creatNewTreeNode('C');
  if (C == NULL) return -1;
  treeNode* D = creatNewTreeNode('D');
  if (D == NULL) return -1;
  treeNode* E = creatNewTreeNode('E');
  if (E == NULL) return -1;
  treeNode* F = creatNewTreeNode('F');
  if (F == NULL) return -1;
  treeNode* G = creatNewTreeNode('G');
  if (G == NULL) return -1;
  treeNode* K = creatNewTreeNode('K');
  if (K == NULL) return -1;
  // 连接节点
  insertTreeNode(A, B, C);
  insertTreeNode(B, D, E);
  insertTreeNode(C, F, G);
  insertTreeNode(F, NULL, K);
  // 遍历节点
}

treeNode* creatNewTreeNode(char data) {
  treeNode* newTreeNode = (treeNode*)malloc(sizeof(treeNode));
  newTreeNode->data = data;
  newTreeNode->LChild = NULL;
  newTreeNode->RChild = NULL;
  return newTreeNode;
}

void insertTreeNode(treeNode* curTreeNode, treeNode* LChildTreeNode, treeNode* RChildTreeNode) {
  curTreeNode->LChild = LChildTreeNode;
  curTreeNode->RChild = RChildTreeNode;
}