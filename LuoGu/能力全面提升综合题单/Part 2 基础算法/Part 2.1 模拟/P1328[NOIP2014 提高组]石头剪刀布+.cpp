#include <iostream>
#define MAXN 2333
using namespace std;

void caiQuan(char a, char b, int *as, int *bs);

int main() {
  char a[MAXN] = {0}, b[MAXN] = {0};
  int T, na, nb, ascore = 0, bscore = 0, ai = 0, bi = 0;
  cin >> T >> na >> nb;
  for (int i = 0; i < na; i++) cin >> a[i];
  for (int i = 0; i < nb; i++) cin >> b[i];
  for (int i = 0; i < T; i++) {
    caiQuan(a[ai], b[bi], &ascore, &bscore);
    ai++, bi++;
    if (ai == na) ai = 0;
    if (bi == nb) bi = 0;
  }
  cout << ascore << " " << bscore << endl;
  return 0;
}

void caiQuan(char a, char b, int *as, int *bs) {
  int sift = 0, win = 0, lost = 0;
  if (a > b) {
    sift = 1;
    char t = a;
    a = b;
    b = t;
  }
  if (a == '0') {  //剪刀
    if (b == '1')
      lost++;
    else if (b == '2')
      win++;
    else if (b == '3')
      win++;
    else if (b == '4')
      lost++;
  } else if (a == '1') {  //石头
    if (b == '2')
      lost++;
    else if (b == '3')
      win++;
    else if (b == '4')
      lost++;
  } else if (a == '2') {  //布
    if (b == '3')
      lost++;
    else if (b == '4')
      win++;
  } else if (a == '3') {  //蜥蜴人
    if (b == '4') win++;
  }
  if (!sift) {
    if (win) (*as)++;
    if (lost) (*bs)++;
  } else {
    if (win) (*bs)++;
    if (lost) (*as)++;
  }
}