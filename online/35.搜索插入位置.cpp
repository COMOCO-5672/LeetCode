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
    if (nums.size() < 0)
      return 0;

    if (nums[0] >= target)
      return 0;

    if (nums[nums.size() - 1] < target)
      return nums.size();

    if (nums[nums.size() - 1] == target) {
      return nums.size() - 1;
    }

    int i = 0;
    int end = nums.size();
    int mid = (i + end) / 2;

    do {
      std::cout << "mid4:" << mid;
      if (nums[mid] > target) {
        std::cout << "mid1:" << mid;
        end = mid;
      } else if (nums[mid] > target) {
        std::cout << "mid2:" << mid;
        i = mid;
      } else {
        std::cout << "mid3:" << mid;
        end = mid;
        break;
      }
      mid = (i + end) / 2;
    } while (end - i > 1);
    return end;
  }
};
// @lc code=end
