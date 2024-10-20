/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <algorithm>
#include <set>
#include <string>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.empty()) {
      return 0;
    }

#if 0
    int start = 0, end = 1; // 最长子串的下标
    int ret = 1;            // 最长子串的长度
    std::set<char> a;       // 判断是否出现重复字符， 这个set的底层是hash表，是一个有序容器

    a.insert(s[start]);

    while (end < s.length()) {
      if (a.find(s[end]) != a.end())
        a.erase(s[start++]);
      else {
        a.insert(s[end++]);
        ret = std::max(ret, end - start);
      }
    }
    return ret;

#endif

    unordered_set<char> char_set;
    int max_length = 0;
    int left = 0;

    for (int right = 0; right < s.length(); right++) {
      while (char_set.count(s[right])) {
        char_set.erase(s[left]);
        left++;
      }
      char_set.insert(s[right]);
      max_length = max(max_length, right - left + 1);
    }

    return max_length;
  }
};
// @lc code=end
