
#include <iostream>
#include <string>

using namespace std;

bool isSubSequence(std::string s, std::string t) {
  int i = 0, j = 0;
  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j]) {
      i++;
    }
    j++;
  }

  return i == s.size();
}

int main() {
  string s1 = "abc", t1 = "ahbgdc";
  string s2 = "axc", t2 = "ahbgdc";

  return 0;
}
