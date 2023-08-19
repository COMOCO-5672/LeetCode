/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
  bool isUgly(int n) {

    if (n < 1)
      return false;

    int tmp = n;

    while (tmp > 1) {
      bool fit_two = tmp % 2 == 0;
      if (fit_two) {
        tmp /= 2;
        continue;
      }

      bool fit_three = tmp % 3 == 0;
      if (fit_three) {
        tmp /= 3;
        continue;
      }

      bool fit_five = tmp % 5 == 0;
      if (fit_five) {
        tmp /= 5;
        continue;
      }

      return false;
    }
    return true;
  }
};
// @lc code=end
