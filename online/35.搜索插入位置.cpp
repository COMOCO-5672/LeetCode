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

#if 0
// 具体来说，你的代码使用了 (low + high) / 2 来计算中间位置，而不是 low + (high - low) / 2。虽然这在大多数情况下不会造成问题，但在处理大数组时可能会导致整数溢出。

// 另外，你的循环条件是 while (low <= high)，这是正确的做法。但在循环结束后，你使用了 return low++，这可能会导致返回值比实际插入位置大1。

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
#endif

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return left;
  }
};
// @lc code=end
