#include <climits>
#include <cmath>
#include <iostream>

// 通过将除数每次乘2和被除数进行对比，
// 直到超过被除数时记下乘2的次数即为结果
int divide2(int dividend, int divisor) {
  if (divisor == 0)
    return INT_MAX;
  if (dividend == INT_MIN && divisor == -1)
    return INT_MAX;

  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

  long long dvd = labs(dividend);
  long long dvs = labs(divisor);

  int res = 0;
  while (dvd >= dvs) {
    long long temp = dvs, multiple = 1;
    while (dvd >= (temp << 1)) {
      temp <<= 1;
      multiple <<= 1;
    }
    dvd -= temp;
    res += multiple;
  }

  return sign * res;
}

int divide(int dividend, int divisor) {
  if (dividend == 0)
    return 0;

  if (dividend == INT_MIN && divisor == -1)
    return INT_MAX;

  int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

  long long dvd = labs(dividend);
  long long dvs = labs(divisor);

  long long quotient = 0;
  long long temp = 0;

  for (int i = 31; i >= 0; i--) {
    if (temp + (dvs << i) <= dvd) {
      std::cout << "i:" << i << "dvs << i" << (dvs << i) << std::endl;
      temp += (dvs << i);
      quotient |= (1LL << i);
    }
  }

  return sign * quotient;
}

int main() {

  int dividend = 0;
  int divisor = 3;

  std::cout << "Result of division" << divide(dividend, divisor) << std::endl;

  return 0;
}
