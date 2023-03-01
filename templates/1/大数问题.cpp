#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B) {
  if (A.size() != B.size()) return A.size() > B.size();
  for (int i = A.size() - 1; i >= 0; --i) {
    if (A[i] < B[i]) return false;
  } 
  return true;
}

vector<int> add(vector<int> &A, vector<int> &B) {
  if (A.size() < B.size()) return add(B, A);
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size(); ++i) {
    t += A[i];
    if (i < B.size()) t += B[i];  
    C.push_back(t % 10);
    t /= 10;
  }
  if (t) C.push_back(1);
  return C;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
  if(!cmp(A, B)) return sub(B, A);
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size(); ++i) {
    t = A[i] - t;
    if (i < B.size()) t -= B[i];
    C.push_back((t + 10) % 10);
    if (t < 0) t = 1;
    else t = 0;
  }
  while (C.size() > 1 && !C.back() == 0) C.pop_back();
  return C;  
}

vector<int> mul(vector<int> &A, int b) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size() || t; ++i) {
    if (i < A.size()) t = A[i] * b;
    C.push_back(t % 10);
    t /= 10;
  }
  return C;
}

vector<int> div(vector<int> &A, int b) {
  vector<int> C;
  int t = 0;
  for (int i= A.size(); i >= 0; --i) {
    t =  t * 10 + A[i] / b;
    C.push_back(t);
    t %= b;
  }
  reverse(C.begin(), C.end());
  while (C.size() > 1 && !C.back()) C.pop_back();
  return C;
}
