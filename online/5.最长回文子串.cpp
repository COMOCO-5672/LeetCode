/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include <string>
#include <vector>

//int dp[1010][1010];

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    // int len = s.size();
    // if (len == 0 || len == 1)
    //   return s;
    // int start = 0; // 回文串起始位置
    // int max = 1;   // 回文串最大长度
    // std::vector<std::vector<int>> dp(len,
    //                                  std::vector<int>(len)); // 定义二维动态数组
    // for (int i = 0; i < len; i++)                            // 初始化状态
    // {
    //   dp[i][i] = 1;
    //   if (i < len - 1 && s[i] == s[i + 1]) {
    //     dp[i][i + 1] = 1;
    //     max = 2;
    //     start = i;
    //   }
    // }
    // for (int l = 3; l <= len;
    //      l++) // l表示检索的子串长度，等于3表示先检索长度为3的子串
    // {
    //   for (int i = 0; i + l - 1 < len; i++) {
    //     int j = l + i - 1;                         // 终止字符位置
    //     if (s[i] == s[j] && dp[i + 1][j - 1] == 1) // 状态转移
    //     {
    //       dp[i][j] = 1;
    //       start = i;
    //       max = l;
    //     }
    //   }
    // }
    // return s.substr(start, max); // 获取最长回文子串

    int n = s.size(), ans = 0;
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));

    for (int i = 0; i < n; i++)
    {
      for (int j = i; j>=0; j--)
      {
        dp[j][i] = (s[i] == s[j] && (i-j <= 2 || dp[j+1][i-1]));
        if()
        {
          
        }
      }
    }
    

  }
};
// @lc code=end
