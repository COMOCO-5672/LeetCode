/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

private:
  vector<string> result;
  unordered_map<char, string> phoneMap = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  void backtrack(const string &digits, int index, string &current) {
    if (index == digits.length()) {
      result.push_back(current);
      return;
    }

    string letters = phoneMap[digits[index]];
    for (char letter : letters) {
      current.push_back(letter);
      backtrack(digits, index + 1, current);
      current.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};

    string current;
    backtrack(digits, 0, current);
    return result;
  }
};
// @lc code=end
