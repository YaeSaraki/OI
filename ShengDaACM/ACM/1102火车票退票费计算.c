#include <stdio.h>

double CancelFee(double price);

int main() {
  double price;
  scanf("%lf", &price);
  printf("%.1lf", CancelFee(price));
  return 0;
}

double CancelFee(double price) {
  price *= 0.05;
  int fee = (int)price;
  if (price - fee < 0.25)
    return fee * 1.0;
  else if (0.25 <= price - fee && price - fee < 0.75)
    return fee + 0.5;
  else
    return fee + 1.0;
}