#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 只是让你找出最小长度并返回
int minSubArrayLen(int target, vector<int> &nums) {

  int n = nums.size();
  int left = 0, right = 0;
  int sum = 0;
  int minLength = INT_MAX;

  while (right < n) {
    sum += nums[right];
    right++;

    while (sum >= target) {
      minLength = std::min(minLength, right - left);
      sum -= nums[left];
      left++;
    }
  }

  return (minLength != INT_MAX) ? minLength : 0;
}

int main() {
  int s = 7;
  std::vector<int> nums = {2, 3, 1, 2, 4, 3};

  int result = minSubArrayLen(1, nums);
  cout << "Minimum length of subarray: " << result << endl;
  return 0;
}
