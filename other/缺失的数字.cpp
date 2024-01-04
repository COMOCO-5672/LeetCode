#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 找出缺失的数字
int findMissingNumber(const vector<int> &nums) {
  // 先排序数组
  vector<int> sortedNums = nums;
  sort(sortedNums.begin(), sortedNums.end());

  // 遍历数组找到缺失的数字
  for (int i = 0; i < sortedNums.size(); ++i) {
    if (sortedNums[i] != i) {
      return i;
    }
  }

  // 如果数组是完整的，返回数组长度
  return sortedNums.size();
}

int main() {
  // 示例用法
  vector<int> nums = {3, 0, 1};

  int missingNumber = findMissingNumber(nums);

  cout << "The missing number is: " << missingNumber << endl;

  return 0;
}
