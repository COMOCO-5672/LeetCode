/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // INT_MAX 最大值是9223372036854775807
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) {
                return 0;
            }

            // INT_MIN 最小值是-9223372036854775808
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) {
                return 0;
            }

            result = result * 10 + pop;
        }
        return result;
    }
};
// @lc code=end

