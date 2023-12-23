#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
  if (s.length() != t.length()) {
    return false;
  }

  unordered_map<char, char> sToT;
  unordered_map<char, char> tToS;

  for (int i = 0; i < s.length(); ++i) {
    char sChar = s[i];
    char tChar = t[i];

    // 检查s到t的映射
    if (sToT.find(sChar) != sToT.end() && sToT[sChar] != tChar) {
      return false;
    }
    sToT[sChar] = tChar;

    // 检查t到s的映射
    if (tToS.find(tChar) != tToS.end() && tToS[tChar] != sChar) {
      return false;
    }
    tToS[tChar] = sChar;
  }

  return true;
}

int main() {
  string s1 = "egg";
  string t1 = "add";
  cout << isIsomorphic(s1, t1) << endl; // 输出 true

  string s2 = "foo";
  string t2 = "bar";
  cout << isIsomorphic(s2, t2) << endl; // 输出 false

  string s3 = "paper";
  string t3 = "title";
  cout << isIsomorphic(s3, t3) << endl; // 输出 true
  return 0;
}
