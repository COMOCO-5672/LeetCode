#include <cctype>
#include <iostream>
#include <stack>

using namespace std;

int calculate(string s) {
  stack<int> numStack;
  stack<int> signStack;
  int result = 0;
  int sign = 1; // 当前的正负号，默认为正

  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (isdigit(c)) {
      int num = 0;
      while (i < s.size() && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        ++i;
      }
      result += sign * num;
      --i;
    } else if (c == '+') {
      sign = 1;
    } else if (c == '-') {
      sign = -1;
    } else if (c == '(') {
      numStack.push(result);
      signStack.push(sign);
      result = 0;
      sign = 1;
    } else if (c == ')') {
      result = signStack.top() * result + numStack.top();
      signStack.pop();
      numStack.pop();
    }
  }
  return result;
}

int main() {
  cout << calculate("1 + 1") << endl;               // 输出 2
  cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl; // 输出 23
  return 0;
}
