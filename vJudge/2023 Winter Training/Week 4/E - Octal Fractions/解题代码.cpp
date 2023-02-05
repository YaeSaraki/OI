#include <string.h>

#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  char input[1001];
  while (~scanf("%s", input)) {
    char answer[1001] = {'0'};
    int d = 0, j;
    for (int i = strlen(input) - 1; i > 1; --i) {
      int num = input[i] - '0';
      for (j = 0; j < d || num; ++j) {
        int temp = num * 10 + (j < d ? answer[j] - '0' : 0);
        answer[j] = temp / 8 + '0';
        num = temp % 8;
      }
       d = j;
    }
    answer[j] = '\0';
    cout << input << " [8] = 0." << answer << " [10]" << endl;
  }
  return 0;
}