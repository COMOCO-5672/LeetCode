#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(std::string s, std::string t) {
  if (s.length() != t.length()) {
    return false;
  }

  unordered_map<char, int> charCount;

  for (char ch : s) {
    charCount[ch]++;
  }

  for (char ch : t) {
    charCount[ch]--;
    if (charCount[ch] < 0) {
      return false;
    }
  }

  return true;
}

int main() { return 0; }
