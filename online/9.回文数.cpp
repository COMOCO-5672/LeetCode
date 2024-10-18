/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start

#include <iostream>
class Solution {
public:
  bool isPalindrome(int x) {
#if 0
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
#endif

    if (x < 0 || (x != 0 && x % 10 == 0)) {
      return false;
    }

    int reversed = 0;
    while (x > reversed) {
      reversed = reversed * 10 + x % 10;
      x /= 10;
      std::cout <<"reversed:" << reversed << ",x:" << x << std::endl;
    }

    return x == reversed || x == reversed / 10;
  }
};

int main()
{
    Solution sol;
    bool ret = sol.isPalindrome(12221);
    std::cout << "ret:" << ret << std::endl;
    return 0;
}

// @lc code=end
