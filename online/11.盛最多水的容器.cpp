/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {

    int left = 0;
    int right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
      int width = right - left;
      int h = min(height[left], height[right]);
      maxWater = max(maxWater, width * h);
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return maxWater;

#if 0

    if (height.size() < 1)
      return 0;

    int start_idx = 0;
    int end_idx = height.size() - 1;

    int maxCap = 0;
    int cacheCap = 0;

    while (start_idx < end_idx) {
      cacheCap =
          (end_idx - start_idx) * min(height[start_idx], height[end_idx]);
      maxCap = max(maxCap, cacheCap);
      if (height[start_idx] < height[end_idx]) {
        start_idx++;
      } else {
        end_idx--;
      }
    }
    return maxCap;

#endif
  }
};
// @lc code=end
