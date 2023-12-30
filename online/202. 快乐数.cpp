#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 可以使用快慢指针的方法，快指针每次计算平方和两次，慢指针每次计算平方和一次，直到两者相等或者快指针达到1。

int getNext(int n) {
  int sum = 0;
  while (n > 0) {
    int digit = n % 10;
    sum += digit * digit;
    n /= 10;
  }
  return sum;
}

bool isHappy(int n) {
  unordered_set<int> seen;
  while (n != 1 && seen.find(n) == seen.end()) {
    seen.insert(n);
    n = getNext(n);
  }
  return n == 1;
}

int main() {
  int num = 19;
  std::cout << isHappy(num) << std::endl;
  return 0;
}
