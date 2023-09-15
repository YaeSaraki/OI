#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>

using namespace std;

// #define cin fin
// #define cout fout
ifstream fin("test.in", ios::in);
ofstream fout("test.out", ios::out);

const int TIME_LIMIT = 86400;
struct Node {
  int arrivalTime, country;
  Node(int a, int b) { arrivalTime = a, country = b; }
};

int main() {
  int allCountries[100100] = {0}, answer = 0;
  deque<Node> deq;
  int T; cin >> T; while (T--) {
    int t, k;
    cin >> t >> k;
    for (int i = 1; i <=k; ++i) {
      int x; cin >> x;
      if (!allCountries[x]) answer++;
      allCountries[x]++;
      deq.push_back(Node(t, x));
    }
    while (t - deq.front().arrivalTime >= TIME_LIMIT) {
      if (!--allCountries[deq.front().country]) answer--;
      deq.pop_front();
    }
    cout << answer << endl;
  }
  return 0;
}