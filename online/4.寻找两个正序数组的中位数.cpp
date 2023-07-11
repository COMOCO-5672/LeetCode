/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    int n = nums1.size() + nums2.size();
    std::vector<int> a(n, 0);
    int i = 0, j = 0, k = 0;
    while (i < nums1.size() && j < nums2.size())
        a[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
    
    // If you add only one array, the other will be abandoned 
    // So you need to check the length
    while (i < nums1.size())
      a[k++] = nums1[i++];

    while (j < nums2.size())
      a[k++] = nums2[j++];

    if (n % 2)
      return a[n / 2];

    return (a[n / 2] + a[n / 2 - 1]) * 0.5;
  }
};
// @lc code=end
