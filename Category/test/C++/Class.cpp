#include <algorithm>
#include <iostream>
using namespace std;

class Clock {
 public:
  void SetTime(int h_new, int m_new, int s_new);
  void ShowTime();
 private:
  int hour_, minute_, second_;
};

void Clock::SetTime(int h_new, int m_new, int s_new) {
  hour_ = h_new, minute_ = m_new, second_ = s_new;
}

void Clock::ShowTime() {
  cout << hour_ << ":" << minute_ << ":" << second_ << endl;
}

int main() {
  Clock MyClock;
  MyClock.SetTime(1, 1, 1);
}