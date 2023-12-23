
#include <iostream>
#include <vector>

using namespace std;

std::vector<int> twoSum(std::vector<int> &number, int target) {
  int left = 0, right = number.size() - 1;
  while (left < right) {
    int sum = number[left] + number[right];
    if (sum == target) {
      // 返回的不是数组的索引，而是数组的位置
      return {left + 1, right + 1};
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }
  return {};
}

int main() {
  std::vector<int> numbers = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> result = twoSum(numbers, target);

  cout << "Indices of two numbers: [" << result[0] << ", " << result[1] << "]"
       << endl;

  return 0;
}
