#include <iostream>
#include <algorithm>
#include <string>


using namespace std;
using ll = long long;

int main() {
  string str; cin >> str;
  ll n; cin >> n;
  ll l = str.length(), t = l;
  while (t < n) t <<= 1;
  
  str = "0" + str;
  
}