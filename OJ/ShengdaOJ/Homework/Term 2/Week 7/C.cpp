#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

struct student {
  ll num;
  string name;
  int chinese, math, english, score;
} stu[100];

bool cmp(student A, student B) {
  if (A.score != B.score) return A.score > B.score;
  return false;
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> stu[i].num >> stu[i].name >> stu[i].chinese >> stu[i].math >> stu[i].english;
    stu[i].score = stu[i].math + stu[i].chinese + stu[i].english;
  }
  sort(stu, stu + n, cmp);
  cout << stu[0].num << " " << stu[0].name << " " << stu[0].chinese << " " << stu[0].math << " " << stu[0].english;
  return 0; 
}