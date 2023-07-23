/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>

class Solution {
public:
  int romanToInt(std::string str) {
    if (str.empty()) {
      return 0;
    }
    int sum = 0;
    auto s = str.c_str();
    do {

      if (s[0] == 'M' || s[0] == 'D')
        sum += s[0] == 'M' ? 1000 : 500;
      if (s[0] == 'L' || s[0] == 'V')
        sum += s[0] == 'L' ? 50 : 5;
      if (s[0] == 'C')
        sum += (s[0] == 'C' && (s[1] == 'D' || s[1] == 'M')) ? -100 : 100;
      if (s[0] == 'X')
        sum += (s[0] == 'X' && (s[1] == 'L' || s[1] == 'C')) ? -10 : 10;
      if (s[0] == 'I')
        sum += (s[0] == 'I' && (s[1] == 'V' || s[1] == 'X')) ? -1 : 1;

    } while (*(++s) != '\0');

    return sum;
  }
};
// @lc code=end
