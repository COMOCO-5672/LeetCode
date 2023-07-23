/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <cstring>
#include <iostream>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    int minLen = -1;
    std::string minLenStr = "";
    for (auto it = strs.begin(); it != strs.end(); ++it) {
      std::cout << "size:" << it->size() << std::endl;
      if (minLen < 0) {
        minLen = it->size();
        minLenStr = *it;
      }
      minLen = it->size() > minLen ? minLen : it->size();
    }

    std::cout << "min_len:" << minLen << std::endl;

    if (minLen < 1)
      return "";

    std::string cacheStr = "";
    bool is_fit = true;
    for (int i = 0; i < minLen; ++i) {
      for (auto it = strs.begin(); it != strs.end(); ++it) {
        if (it->at(i) != minLenStr.at(i)) {
          std::cout << "char:" << minLenStr.at(i) << std::endl;
          is_fit = false;
          break;
        };
      }

      if (!is_fit)
        break;

      cacheStr += minLenStr.at(i);
    }
    return cacheStr;
  }
};

// int main() {
//   std::vector<std::string> str;
//   str.emplace_back("flower");
//   str.emplace_back("flow");
//   str.emplace_back("flight");

//   Solution a;
//   auto com_str = a.longestCommonPrefix(str);
//   std::cout << "com_str:" << com_str << std::endl;
//   return 0;
// }

// @lc code=end
