#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 滑动窗口

std::vector<int> findSubString(std::string s, std::vector<std::string> &words) {
  std::vector<int> result;

  if (s.empty() || words.empty()) {
    return result;
  }

  int wordLen = words[0].size();
  int wordCount = words.size();
  int totalLen = wordCount * wordLen;

  std::unordered_map<std::string, int> wordFreq;

  // 统计每个单词出现的次数
  for (const std::string &word : words) {
    wordFreq[word]++;
  }

  for (int i = 0; i < wordLen; ++i) {
    int left = i, right = i, count = 0;
    std::unordered_map<std::string, int> currWordFreq;

    while (right + wordLen <= s.size()) {
      std::string currWord = s.substr(right, wordLen);
      right += wordLen;

      if (wordFreq.find(currWord) == wordFreq.end()) {
        // 当前单词不在words中，重新计数
        count = 0;
        left = right;
        currWordFreq.clear();
      } else {
        // 当前单词在words中
        count++;
        currWordFreq[currWord]++;

        // 如果当前单词的出现次数超过了words中的次数，缩小窗口
        while (currWordFreq[currWord] > wordFreq[currWord]) {
          std::string leftWord = s.substr(left, wordLen);
          count--;
          currWordFreq[leftWord]--;
          left += wordLen;
        }

        if (count == wordCount) {
          result.emplace_back(left);
        }
      }
    }
  }
  return result;
}

int main() {
  string s = "barfoothefoobarman";
  vector<string> words = {"foo", "bar"};

  vector<int> result = findSubString(s, words);

  cout << "Starting indices of concatenated substrings: [";
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i];
    if (i < result.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
  return 0;
}
