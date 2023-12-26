#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// WARNNING: 注意：这道题运行结果是错误的
std::vector<std::vector<std::string>>
groupAnagrams(std::vector<std::string> &strs) {
  std::vector<std::vector<std::string>> result;
  std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

  for (const std::string &str : strs) {
    // 统计字符串中字符出现的次数
    unordered_map<char, int> charCount;
    for (char ch : str) {
      charCount[ch]++;
    }

    // 构建字符频次的唯一标识
    std::string key;
    for (auto &entry : charCount) {
      key += entry.first;
      key += to_string(entry.second);
    }

    // 将同一组的字符串放在同一个vector中
    anagramGroups[key].emplace_back(str);
  }

  // 将哈希表中的分组转换为结果向量
  for (auto &entry : anagramGroups) {
    result.emplace_back(entry.second);
  }

  return result;
}

int main() {
  // 示例用法
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> result = groupAnagrams(strs);

  // 输出结果
  for (const auto &group : result) {
    cout << "[";
    for (const string &str : group) {
      cout << "\"" << str << "\", ";
    }
    cout << "], ";
  }
  return 0;
}
