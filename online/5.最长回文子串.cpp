/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
  std::string longestPalindrome(std::string s) {

    // 动态规划
    // 状态：dp[i][j]描述的s(i) == s(j) 是否相等，并更新二维表
    // 状态转移方程：dp[i][j] = (s[i] == s[j]) and dp[i-1][j-1]
    // 边界：j-1 - (i+1) + 1 < 2 时停止，因为2-0 = 2 但是实际上有三个数，所以要加一
    // 初始化：dp[i][i] = true;
    int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                std::cout << "j:" << j << "L:" << L << "i:" << i << std::endl;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                  std::cout << "over" << std::endl;
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);

  }
};

#if 1

int main()
{
  Solution sol;
  std::string str = sol.longestPalindrome("aaadddadddd");
  std::cout << str << std::endl;
  return 0;
}

#endif

// @lc code=end
