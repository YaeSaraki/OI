#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

vector<queue<int> > teamQueue;
queue<int> number_noTeam;
map<int, int> queueNumber;

void Enqueue(), Dequeue();

int main() {
  int n, scenarioTime = 0;
  while (cin >> n, n) {
    cout << "Scenario #" << ++scenarioTime << endl;
    for (int i = 0; i < n; ++i) {
      int m; cin >> m;
      queue<int> tempQueue;
      for (int j = 0; j < m; ++j) {
        int x; cin >> x;
        tempQueue.push(x);
        queueNumber.insert(pair<int, int>(x, 0));
      }
      teamQueue.push_back(tempQueue);
    }
    string input;
    while (cin >> input, input != "STOP") {
      if (input == "ENQUEUE") Enqueue();
      if (input == "DEQUEUE") Dequeue();
    }
    cout << endl;
  }
  return 0;
}

void Enqueue() {
  int number; cin >> number;
  if (queueNumber.find(number) == queueNumber.end()) {
    queueNumber.insert(pair<int, int>(number, 1));
    number_noTeam.push(number);
    teamQueue.push_back(number_noTeam);
  } else {
    queueNumber[number]++;
  }
}

void Dequeue() {
  for (int i = 0; i < teamQueue.size(); ++i) {
    while (!teamQueue[i].empty() && queueNumber[teamQueue[i].front()] > 0) {
      cout << teamQueue[i].front() << endl;
      queueNumber[teamQueue[i].front()]--;
      teamQueue[i].pop();
      return;
    }
  }
}