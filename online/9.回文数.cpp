/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    __int64_t reversedNum = 0;
    int num = x;
    while (num != 0) {
      int digit = num % 10;
      reversedNum = reversedNum * 10 + digit;
      num /= 10;
    }

    return x == reversedNum;
  }
};
// @lc code=end
