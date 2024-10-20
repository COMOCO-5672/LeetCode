/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  // 中心扩散法
  std::string longestPalindrome3(std::string s) {
    if (s.length() < 2) {
      return s;
    }

    int start = 0, maxLength = 1;

    for (int i = 0; i < s.length(); i++) {
      expandAroundCenter(s, i, i, start, maxLength);     // 奇数长度
      expandAroundCenter(s, i, i + 1, start, maxLength); // 偶数长度
    }

    return s.substr(start, maxLength);
  }

private:
  void expandAroundCenter(const std::string &s, int left, int right, int &start,
                          int &maxlength) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      left--;
      right++;
    }

    int length = right - left - 1;
    if (length > maxlength) {
      start = left + 1;
      maxlength = length;
    }
  }

public:
  std::string longestPalindrome2(std::string s) {
    std::string v = "";
    std::vector<std::vector<bool>> dp(s.size(),
                                      std::vector<bool>(s.size(), false));
    for (int i = s.size() - 1; i >= 0; i--) {
      for (int j = i; j < s.size(); j++) {
        if (i == j) { // 当i和j相等时为true
          dp[i][j] = true;
          if (j - i + 1 > v.size())
            v = s.substr(i, j - i + 1);
        } else if (s[i] == s[j] &&
                   j - i == 1) { // 当i和j相邻且两个元素相等时为true
          dp[i][j] = true;
          if (j - i + 1 > v.size())
            v = s.substr(i, j - i + 1);
        } else if (
            s[i] == s[j] &&
            dp[i + 1]
              [j - 1]) { // 当i和j对应的两个元素相等且中间子串为回文串时为true
          dp[i][j] = true;
          if (j - i + 1 > v.size())
            v = s.substr(i, j - i + 1);
        }
      }
    }
    return v;
  }

  std::string longestPalindrome(std::string s) {

    // 动态规划
    // 状态：dp[i][j]描述的s(i) == s(j) 是否相等，并更新二维表
    // 状态转移方程：dp[i][j] = (s[i] == s[j]) and dp[i-1][j-1]
    // 边界：j-1 - (i+1) + 1 < 2 时停止，因为2-0 = 2
    // 但是实际上有三个数，所以要加一 初始化：dp[i][i] = true;
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
    // 先枚举子串长度,单个字符不能构成回文串，至少有两个字符，L=2
    // 表示长度是2，但是需要转换为索引
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
          // 这里的j-i<3
          // 表示的是要小于等于2，如果两个字符，则两个字符相等，如果是三个字符，左右相等即可。
          if (j - i < 3) {
            dp[i][j] = true;
          } else {
            // 收缩长度
            dp[i][j] = dp[i + 1][j - 1];
          }
        }

        // 只要 dp[i][L] == true 成立，就表示子串 s[i..L]
        // 是回文，此时记录回文长度和起始位置
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

int main() {
  Solution sol;
  std::string str = sol.longestPalindrome("aaadddadddd");
  std::cout << "str:" << str << std::endl;
  return 0;
}

#endif

// @lc code=end
