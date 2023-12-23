#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 可以使用哈希表记录每个字符在 magazine 中出现的次数。
// 然后遍历 ransomNote 中的每个字符，检查其在 magazine 中的出现次数是否足够。

bool canConstruct(string ransomNote, string magazine) {
  unordered_map<char, int> charCount;

  for (char ch : magazine) {
    charCount[ch]++;
  }

  for (char ch : ransomNote) {

    if (charCount[ch] <= 0) {
      return false; // 没有足够的字符组成目标字符
    }
    charCount[ch]--;
  }

  return true;
}

int main() {
  string ransomNote1 = "a";
  string magazine1 = "b";
  cout << canConstruct(ransomNote1, magazine1) << endl; // 输出 false

  string ransomNote2 = "aa";
  string magazine2 = "ab";
  cout << canConstruct(ransomNote2, magazine2) << endl; // 输出 false

  string ransomNote3 = "aa";
  string magazine3 = "aab";
  cout << canConstruct(ransomNote3, magazine3) << endl; // 输出 true
  return 0;
}
