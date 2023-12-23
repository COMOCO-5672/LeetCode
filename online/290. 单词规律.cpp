#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// 可以使用两个哈希表分别记录 pattern 到 str 和 str 到 pattern 的映射关系。
// 遍历 pattern 和 str 的每个单词，检查其映射关系是否符合规律。

bool wordPattern(string pattern, string str) {
  unordered_map<char, string> patternToStr;
  unordered_map<string, char> strToPattern;

  stringstream ss(str);
  string word;

  for (char ch : pattern) {
    if (!(ss >> word)) {
      return false; // 单词不足，无法继续匹配
    }

    if (patternToStr.find(ch) != patternToStr.end() &&
        patternToStr[ch] != word) {
      return false;
    }
    patternToStr[ch] = word;

    if (strToPattern.find(word) != strToPattern.end() &&
        strToPattern[word] != ch) {
      return false;
    }
    strToPattern[word] = ch;
  }

  if (ss >> word) {
    return false;
  }

  return true;
}

int main() {
  string pattern1 = "abba";
  string str1 = "dog cat cat dog";
  cout << wordPattern(pattern1, str1) << endl; // 输出 true

  string pattern2 = "abba";
  string str2 = "dog cat cat fish";
  cout << wordPattern(pattern2, str2) << endl; // 输出 false

  string pattern3 = "aaaa";
  string str3 = "dog cat cat dog";
  cout << wordPattern(pattern3, str3) << endl; // 输出 false

  string pattern4 = "abba";
  string str4 = "dog dog dog dog";
  cout << wordPattern(pattern4, str4) << endl; // 输出 false
  return 0;
}
