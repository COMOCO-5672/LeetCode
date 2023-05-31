#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twosum(std::vector<int> &A, int target) {
  std::unordered_map<int, int> m;
  for (int i = 0;; ++i) {
    int x = A[i];
    int y = target - x;
    if (m.count(y)) {
      return {m[y], i};
    }
    m[x] = i;
  }
}

int main() {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> ret = twosum(nums, 9);
  std::cout << "size:" << ret.size() << "\r\n" << std::endl;
  for (int i = 0; i < ret.size(); ++i) {
    std::cout << "id:" << ret[i] << "\r\n" << std::endl;
  }

  return 0;
}
