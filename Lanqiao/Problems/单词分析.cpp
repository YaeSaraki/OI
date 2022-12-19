#include <iostream>
#include <algorithm>

using namespace std;

string words;
int num[128];

int main(){
  int maxn = 0, maxi=0;
  cin >> words;
  for (int i = 0; i < (int)words.length(); i++) num[(int)words[i]]++;
  for (int i = 'a'; i <= 'z'; i++) {
    if (num[i] > maxn) {
      maxi = i;
      maxn = num[i];
    }
  }
  printf("%c\n", maxi);
  printf("%i\n", maxn);
  return 0;
} 