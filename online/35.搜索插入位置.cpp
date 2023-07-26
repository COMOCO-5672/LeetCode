/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = (low + high) / 2;

    while (low <= high) {
      if (nums[mid] == target) {
        return mid;
      } else if (target < nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
      mid = (low + high) / 2;
    }
    return low++;
  }
};
// @lc code=end
