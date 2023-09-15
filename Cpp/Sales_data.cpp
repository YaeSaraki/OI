

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define DBG(x) std::cout << #x << " = " << (x) << '\n'
//#define int long long

using i64 = int64_t;
using PI = std::pair<int, int>;


struct Sales_data {
  std::string bookNo;
  double revenus = 0;
  unsigned units_sold = 0;

  inline
    std::string isbn() const { return bookNo; }
  inline
    Sales_data& combine(const Sales_data&);
  inline
    double avg_price() const;
};

double Sales_data::avg_price() const {
  if (units_sold) return revenus / units_sold;
  else return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenus += rhs.revenus;
  return *this;
}

std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenus = price * item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " <<
        item.revenus << " " << item.avg_price();
  return os;
}


/* Sales_data的非成员接口函数 */
Sales_data add(Sales_data&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

inline void solve() {}

bool rt = false;
signed main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  if (rt) { int T; std::cin >> T; while (T--) solve(); }
  else solve();
  return (0 ^ 0);
}

