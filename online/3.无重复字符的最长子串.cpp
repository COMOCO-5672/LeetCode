/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) { 
    int length = s.size();
    int i = 0;

    int maxLen = 0;
    int cacheLen = 0;
    std::unordered_map<std::string, int> map;

    while (i < length)
    {
      auto a = s.at(i);
      i++;
      std::string m(1, a);
      if (map.find(m) == map.end())
      {
        map.insert(std::pair(m, 0));
        cacheLen++;
        continue;
      }

      if(cacheLen > maxLen)
      {
        maxLen = cacheLen;
      }
      map.clear();
      cacheLen=0;
    }
    return maxLen;
    }
};
// @lc code=end

