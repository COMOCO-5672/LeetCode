/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
#if 0
    int length = digits.size();
    int flow = 1;
    for (int i = length - 1; i >= 0; i--) {
      if (flow) {
        if (digits[i] + 1 > 9) {
          digits[i] = (digits[i] + 1) % 10;
          flow = 1;
          if (i == 0) {
            digits.insert(digits.begin(), 1);
            break;
          }
        } else {
          digits[i] += 1;
          break;
        }
      } else {
        break;
      }
    }
    return digits;
#endif

    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] < 9) {
        digits[i]++;
        return digits;
      }
      digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};
// @lc code=end
