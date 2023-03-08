
#include <iostream>
#include <algorithm>
using namespace std;
int ToS(int h, int m, int s, int t) {
  int time = h * 3600 + m * 60 + s + t * (3600 * 24);
  return time;
}
int main() {
  int T; cin >> T; while(T--) {
    int h_1, m_1, s_1, h_2, m_2, s_2, t1, t2, t3, t4, t = 0;
    scanf("%d:%d:%d %d:%d:%d (+%d)", &h_1, &m_1, &s_1, &h_2, &m_2, &s_2, &t);
    t1 = ToS(h_1, m_1, s_1, 0);
    t2 = ToS(h_2, m_2, s_2, t); 
    t3 = t2 - t1;
    t = 0;
    scanf("%d:%d:%d %d:%d:%d (+%d)", &h_1, &m_1, &s_1, &h_2, &m_2, &s_2, &t);
    t1 = ToS(h_1, m_1, s_1, 0);
    t2 = ToS(h_2, m_2, s_2, t);
    t = 0;
    t4 = t2 - t1;
    t2 = (t3 + t4) / 2;
    h_1 = t2 / 3600, m_1 = t2 % 3600 / 60, s_1 = t2 % 60;
    printf("%02d:%02d:%02d\n", h_1, m_1, s_1);
  }
  return 0; 
}