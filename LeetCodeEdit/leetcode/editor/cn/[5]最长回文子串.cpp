//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 7034 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

#include <string>
#include <vector>

class Solution {
public:
    string longestPalindrome(string s) {
        std::string v = "";
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        for (int i = s.size()-1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (i == j) {
                    dp[i][j] = true;
                    if (j-i+1 > v.size())
                    {
                        v = s.substr(i, j-i+1);
                    }
                } else if (s[i] == s[j] && j-i == 1) {
                    dp[i][j] = true;
                    if (j-i+1 > v.size())
                    {
                        v = s.substr(i, j-i+1);
                    }
                } else if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (j-i+1 > v.size())
                    {
                        v = s.substr(i, j-i+1);
                    }
                }
            }
        }
        return v;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
