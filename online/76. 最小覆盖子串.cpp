#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 滑动窗口

std::string minWindow(std::string s, std::string t) {
  std::unordered_map<char, int> targetFreq, windowFreq;

  for (char c : t) {
    targetFreq[c]++;
  }

  int left = 0, right = 0;               // 双指针
  int minLen = INT_MAX;                  // 记录最小子串的长度
  int start = 0;                         // 计算最小子串的起始位置
  int requiredChars = targetFreq.size(); // 需要的不同字符的数量

  while (right < s.size()) {
    char currChar = s[right];
    windowFreq[currChar]++;

    if (targetFreq.find(currChar) != targetFreq.end() &&
        windowFreq[currChar] == targetFreq[currChar]) {
      requiredChars--;
    }

    while (requiredChars == 0) {
      if (right - left + 1 < minLen) {
        minLen = right - left + 1;
        start = left;
      }
      char leftChar = s[left];
      windowFreq[leftChar]--;

      if (targetFreq.find(leftChar) != targetFreq.end() &&
          windowFreq[leftChar] < targetFreq[leftChar]) {
        requiredChars++;
      }

      left++;
    }
    right++;
  }

  return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
}

int main() {
  std::string s = "ADOBECODEBANC";
  std::string t = "ABC";

  std::string result = minWindow(s, t);

  cout << "Minimum window substring: " << result << endl;

  return 0;
}
