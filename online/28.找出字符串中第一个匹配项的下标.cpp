/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int len1 = haystack.size(), len2 = needle.size();

    if (len2 < 1 || len1 < 1) {
      return -1;
    }

    int l1 = 0, l2 = 0, match = 0, index = 0;
    int sign = -1;
    while (l1 < len1 && l2 < len2) {
      if (haystack[l1] == needle[l2]) {
        if (haystack[l1] = needle[0] && sign == -1) {
          index = l1;
          sign = 1;
        }

        ++match;
        ++l1;
        ++l2;
        continue;
      }
      l2 = 0;
      sign = -1;
      if (match > 0) {
        l1 = l1 - match + 1;
      } else {
        ++l1;
      }
      match = 0;
      index = 0;
    }
    return match == len2 ? index : -1;
  }
};
// @lc code=end
