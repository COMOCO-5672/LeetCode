#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path) {
  vector<string> parts;
  string part;
  istringstream ss(path);

  // 按照'/'进行分割
  while (getline(ss, part, '/')) {
    if (part == "." || part.empty()) {
      // 当前目录或为空，不进行操作
      continue;
    } else if (part == "..") {
      if (!parts.empty()) {
        parts.pop_back();
      }
    } else {
      parts.emplace_back(part);
    }
  }
  // 将数据进行进行连接
  string result = "/";
  for (const string &p : parts) {
    result += p + "/";
  }

  // 去掉末尾的'/'
  if (result.size() > 1) {
    result.pop_back();
  }
  return result;
}

int main() {
  cout << simplifyPath("/home/") << endl;          // 输出 "/home"
  cout << simplifyPath("/a/./b/../../c/") << endl; // 输出 "/c"
  cout << simplifyPath("/../") << endl;            // 输出 "/"
  cout << simplifyPath("/home//foo/") << endl;     // 输出 "/home/foo"
  return 0;
}
