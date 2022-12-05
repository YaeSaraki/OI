#include <bits/stdc++.h>
using namespace std;

string _O;
string code;

int sread(int &x, string s);
int getO();

int main(){
  int T; cin >> T; while(T--) {
    int L; cin >> L; while(L--) {
      cin >> _O; int _o= getO();//获得输入的复杂度。若复杂度为常数，则_o(复杂度记录变量)为0
    }
  
  }

}

int sread(int &x, string s){
  int res = 0;
  while ('0' <= s[x] && s[x] <= '9'&& x < s.size()) {
    res = res * 10 + (s[x] - '0');
    x++;
  }
  return res;
}

int getO(){
  int res = 0, x = 3;
  if (_O[2]=='n') res = sread(x,_O);
  return res;
}