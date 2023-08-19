/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    static bool is_bad = false;
    int i = 1;

    while (i <= n) {
      if (isBadVersion(i)) {
        is_bad = true;
        return i;
      }

      i++;
    }
    return --i;
  }
};
// @lc code=end
