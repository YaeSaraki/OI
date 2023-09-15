#include <iostream>
#include <algorithm>

using namespace std; 


int main() {
  int n ; cin >> n ; 
  int minn = 0 , maxx = 2e9 ; 
  for(int i = 1 ; i <= n ; i ++) {    
    int a, b ; cin >> a >> b ; 
    int r = a / b , l = a / (b + 1) + 1;
    minn = max(minn , l) , maxx = min(maxx , r) ; 
  }
  cout << minn << ' ' << maxx << endl ; 
  return 0;
}

