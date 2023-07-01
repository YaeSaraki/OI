// https://vjudge.csgrandeur.cn/problem/UVA-1589
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

char board[23][23];
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

struct Point {
  int r, c;
  bool operator <(const Point &B) const { return (r < B.r || (r == B.r && c < B.c)); }
  bool operator !=(const Point &B)const { return r != B.r || c != B.c; }
  bool operator ==(const Point &B)const { return r == B.r && c == B.c; }
  Point operator +(Point &B) {
    Point t;
    t.r = r + B.r, t.c = c + B.c;
    return t;
  }
};
struct Piece {
  char name;
  Point point;
};

vector<Piece> all_red_Piece;
set<Point> all_next_black_bossPoint;

bool isVertical(Point A, Point B) { // judege if A and B are vertical
  return A.c == B.c;
}
bool isHorizontal(Point A, Point B) { //judge if A and B are horizontal
  return A.r == B.r;
}

int PieceCnt(Point A, Point B) { // number that all pieces from A to B
  int cnt = 0;
  int r_min = min(A.r, B.r), r_max = max(A.r, B.r);
  int c_min = min(A.c, B.c), c_max = max(A.c, B.c);
  if (isHorizontal(A, B)) {
    for (int c = c_min + 1; c < c_max; ++c) {
      if (board[A.r][c] != '*') ++cnt;
    }
    return cnt;
  }
  if (isVertical(A, B)) {
    for (int r = r_min + 1; r < r_max; ++r) {
      if (board[r][A.c] != '*') ++cnt;
    }
    return cnt;
  }
  return -1;
}

bool isChecked(Point bossPoint) {
  for (auto it = all_red_Piece.begin(); it != all_red_Piece.end(); ++it) {
    if (it->name == 'G' || it->name == 'R') {
      if (PieceCnt(it->point, bossPoint) == 0 && it->point != bossPoint) return true;
    } else if (it->name == 'C') {
    // cout << "PieceCnt: " << PieceCnt(it->point, bossPoint) << endl;
      if (PieceCnt(it->point, bossPoint) == 1) return true;
    } else if (it->name == 'H') {
      for (int i = 0; i < 4; ++i) {
        // Point temp(it->point + (Point){dir[i][0], dir[i][1]});
        Point temp;
        temp.r = it->point.r + dir[i][0];
        temp.c = it->point.c + dir[i][1];
        if (temp.r < 1 || temp.c < 1) continue;
        if (board[temp.r][temp.c] != '*' || temp == bossPoint) continue;
        Point ljump, rjump;
        if (dir[i][0]) {
          ljump.r = rjump.r = dir[i][0];
          ljump.c = -1, rjump.c = 1;
        } else {
          ljump.c = rjump.c = dir[i][1];
          ljump.r = -1, rjump.r = 1;
        }
      //  cout << (temp + ljump).c << " " << (temp + ljump).r << endl;
      //  cout << (temp + rjump).c << " " << (temp + rjump).r << endl;
        if (temp + ljump == bossPoint || temp + rjump == bossPoint) return true;
      }
    }
  }
  return false;
}

set<Point> getNextBoosPoint(Point A) {
  set<Point> s;
  for (int i = 0; i < 4; ++i) {
    int next_point_r = A.r + dir[i][0], next_point_c = A.c + dir[i][1];
    if (3 < next_point_c && next_point_c < 7 && 
        0 < next_point_r && next_point_r < 4)
      s.insert({next_point_r, next_point_c});
  }
  return s;
}

inline void solve() {
  int N;
  Point bossPoint;
  while (cin >> N >> bossPoint.r >> bossPoint.c && N) {
    all_red_Piece.clear();
    memset(board, '*', sizeof(board));
    //input red piecees
    Piece redPiece;
    while(N--) { 
      cin >> redPiece.name >> redPiece.point.r >> redPiece.point.c;
      board[redPiece.point.r][redPiece.point.c] = redPiece.name;
      all_red_Piece.push_back(redPiece);
    }
    //the situation that wins at begin
    bool win = false; 
    for (auto it = all_red_Piece.begin(); it != all_red_Piece.end(); ++it) {
      if (it->name == 'G' && isVertical(it->point, bossPoint) &&
          PieceCnt(it->point, bossPoint) == 0) win = true;
    }
    if (win) { cout << "NO" << endl; continue; }
    //test for move
    all_next_black_bossPoint = getNextBoosPoint(bossPoint);
  // cout << "size: " << all_next_black_bossPoint.size() << endl;
    for (auto it = all_next_black_bossPoint.begin(); // if need erase element when in set loop, use this codes.
         it != all_next_black_bossPoint.end();) {
      if (isChecked(*it)) all_next_black_bossPoint.erase(it++);
      else ++it;
    }
    if (all_next_black_bossPoint.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return;
}

bool rt = false;

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  #endif
  if (rt) { int T; cin >> T; while(T--) solve(); }
  else solve();
  return 0;
}