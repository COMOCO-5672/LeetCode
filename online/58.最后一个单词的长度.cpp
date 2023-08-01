/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start

#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int ret = 0;
        int length = s.length();

        for (int i = 0; i < length; ++i)
        {
            if (s.at(i) == ' ' && i + 1 < length && s.at(i+1) != ' ')
            {
                ret = 0;
                continue;
            }

            if (s.at(i) != ' ')
            {
                ++ret;
            }
        }

        return ret;
    }
};
// @lc code=end

