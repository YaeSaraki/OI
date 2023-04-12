#include <iostream>
#include <algorithm>
using namespace std;

const int Y = 8000, L = 4000, C = 2000, X = 1000 ,B = 850;
struct student {
  char name[20];
  int score_average, evaluation_results, thesis_number;
  int scholorship = 0;
  char isleader, iswest;
  bool operator < (const student &a) const {
    if (a.scholorship != scholorship) return scholorship > a.scholorship;
    return false; 
  }
} s[100];

int main() {
  int n; cin >> n;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s %i %i %c %c %i", 
          s[i].name, &s[i].score_average, &s[i].evaluation_results, 
          &s[i].isleader, &s[i].iswest, &s[i].thesis_number);
    
    if (s[i].score_average > 80 && s[i].thesis_number >= 1) s[i].scholorship += Y;
    if (s[i].score_average > 85 && s[i].evaluation_results > 80) s[i].scholorship += L;
    if (s[i].score_average > 90) s[i].scholorship += C;
    if (s[i].score_average > 85 && s[i].iswest == 'Y') s[i].scholorship += X;
    if (s[i].evaluation_results > 80 && s[i].isleader == 'Y') s[i].scholorship += B; 
    sum += s[i].scholorship;
  }
  sort(s, s + n);
  cout << s[0].name << '\n' << s[0].scholorship << '\n' << sum;
  return 0;
}