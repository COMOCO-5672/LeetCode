/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string s) {
    if (s.empty())
      return true;
    std::stack<char> stack;

    for (auto it = s.begin(); it != s.end(); ++it) {

      if ((*it == ')' || *it == '}' || *it == ']') && !stack.empty()) {

        if (*it == ')' && stack.top() == '(') {
          stack.pop();
          continue;
        }

        if (*it == '}' && stack.top() == '{') {
          stack.pop();
          continue;
        }

        if (*it == ']' && stack.top() == '[') {
          stack.pop();
          continue;
        }
      }
      stack.push(*it);
    }

    return stack.empty();
  }
};

// @lc code=end
