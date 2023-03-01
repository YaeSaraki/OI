#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

#define cin fin
#define cout fout
ifstream fin("test.in", ios::in);
ofstream fout("test.out", ios::out);

struct Node {
  int position, step;
  Node(int a, int b) { position = a, step = b; };
};

const int FARLANDS = 100001;

bool haspassed[2 * FARLANDS];
int john_position, cow_position;
int BreadthFirstSearch();

int main() {
    cin >> john_position >> cow_position;
    cout << BreadthFirstSearch() << endl;
  return 0;
}

int BreadthFirstSearch() {
  memset(haspassed, 0, sizeof(haspassed));
  if (john_position >= cow_position) return john_position - cow_position;
  queue<Node> queue;
  haspassed[john_position] = true;
  queue.push(Node(john_position, 0));
  while (!queue.empty()) {
    Node now = queue.front();
    queue.pop();
    int next_position; // <- 1 2 3 
    if (now.position == cow_position) return now.step;
    next_position = now.position + 1;  // 1
    if (!haspassed[next_position] && next_position <= cow_position &&
        (0 <= next_position && next_position <= FARLANDS)) {
      queue.push(Node(next_position, now.step + 1));
      haspassed[next_position] = true;
    }
    next_position = now.position - 1;  // 2
    if (!haspassed[next_position] &&
        (0 <= next_position && next_position <= FARLANDS)) {
      queue.push(Node(next_position, now.step + 1));
      haspassed[next_position] = true;
    }
    next_position = now.position * 2;  // 3
    if (!haspassed[next_position] &&
        (0 <= next_position && next_position <= FARLANDS)) {
      queue.push(Node(next_position, now.step + 1));
      haspassed[next_position] = true;
    }
  }
  return -1;
}