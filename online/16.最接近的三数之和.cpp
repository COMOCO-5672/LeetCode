/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    int result_sum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {
      int left = i + 1, right = n - 1;
      while (left < right) {
        int current_sum = nums[i] + nums[left] + nums[right];
        if (current_sum == target) {
          return current_sum;
        }

        if (abs(current_sum - target) < abs(result_sum - target)) {
          result_sum = current_sum;
        }

        if (current_sum < target) {
          left++;
        } else {
          right--;
        }
      }
    }
    return result_sum;
  }
};
// @lc code=end
