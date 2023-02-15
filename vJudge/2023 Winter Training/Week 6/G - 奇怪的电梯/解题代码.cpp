#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

// #define cin fin
ifstream fin("test.in");

struct Node {
  int floor, time;
  Node(int a, int b) { floor = a, time = b; };
};

const int FARLANDS = 202;
int N, A, B;
int lift[FARLANDS];
bool haspassed[FARLANDS];

int BreadthFirstSearch(int floor);

int main() {
  cin >> N >> A >> B;
  for (int i = 1; i <= N; ++i) cin >> lift[i];
  cout << BreadthFirstSearch(A) << endl;
  return 0;
}

int BreadthFirstSearch(int floor) {
  queue<Node> queue;
  queue.push(Node(floor, 0));
  haspassed[floor] = true;
  while (!queue.empty()) {
    Node now = queue.front();
    queue.pop();
    if (now.floor == B) return now.time;
    int flag = -1;
    for (int i = 1; i <= 2; ++i) {
      flag = -flag;
      int floor_next = now.floor + (lift[now.floor] * flag);
      if ((0 < floor_next && floor_next <= B)&& !haspassed[floor_next]) {
        haspassed[floor_next] = true;
        queue.push(Node(floor_next, now.time + 1));
      }
    }
  }
  return -1;
}