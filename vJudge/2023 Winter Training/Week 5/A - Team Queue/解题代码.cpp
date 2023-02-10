#include <iostream>
#include <map>
#include <queue>
#include <fstream>
using namespace std;

// #define cout fout
// #define cin fin
// ifstream fin("test.in", ios::in);
// ofstream fout("test.out", ios::out);

int main() {
  int n, scenarioTime = 0;
  while (scanf("%d", &n), n != 0) {
    map<int, int> number_team;  
    printf("Scenario #%d", ++scenarioTime);
    for (int i = 0; i < n; ++i) {
      int m; scanf("%d", &m);
      for (int j = 0; j < m; ++j) {
        int x; scanf("%d", &x);
        number_team[x] = i;
      }
    }
    char input[66];
    queue<int> teamQueue, numberQueue[10010];  
    while (scanf("%s", input), input[0] != 'S') {
      if (input[0] == 'E') {
        int number;
        scanf("%d", &number);
        int team = number_team[number];
        if (numberQueue[team].empty()) teamQueue.push(team);
        numberQueue[team].push(number);
      }
      if (input[0] == 'D') {
        int team = teamQueue.front();
        if (!numberQueue[team].empty()) {
          printf("%d\n", numberQueue[team].front());
          numberQueue[team].pop();
        }
        if (numberQueue[team].empty()) teamQueue.pop();
      }
    }
    printf("\n");
  }
  return 0;
}

