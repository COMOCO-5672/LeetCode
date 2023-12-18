#include <iostream>
#include <istringstream>
#include <string>
#include <vector>

using namespace std;

std::string reverseWords(std::string s) {
  // 使用字符串读取单词
  std::istringstream iss(s);
  std::string word;
  std::vector<std::string> words;

  // 将单词存储在向量中
  while (iss >> word) {
    words.emplace_back(word);
  }

  // 翻转单词
  std::reverse(words.begin(), words.end());

  // 输出短语，并添加空格
  stringstream ss;
  for (const std::string &w : words) {
    ss << w << " ";
  }

  std::string result = ss.str();
  result.pop_back(); // 移除最后一个空格

  return result;
}

int mian() { return 0; }
