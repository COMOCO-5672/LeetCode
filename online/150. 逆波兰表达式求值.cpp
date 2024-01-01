#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int evalRPN(vector<string> &tokens) {
  stack<int> numStack;

  for (const string &token : tokens) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      // 遇到运算符，弹出栈顶的两个元素进行运算，并将结果入栈
      int num2 = numStack.top();
      numStack.pop();
      int num1 = numStack.top();
      numStack.pop();

      if (token == "+") {
        numStack.push(num1 + num2);
      } else if (token == "-") {
        numStack.push(num1 - num2);
      } else if (token == "*") {
        numStack.push(num1 * num2);
      } else if (token == "/") {
        numStack.push(num1 / num2);
      } else {
        numStack.push(stoi(token));
      }
    }
  }

  // 最终栈中的唯一元素即为结果
  return numStack.top();
}

int main() {
  vector<string> tokens1 = {"2", "1", "+", "3", "*"};
  cout << evalRPN(tokens1) << endl; // 输出 9

  vector<string> tokens2 = {"4", "13", "5", "/", "+"};
  cout << evalRPN(tokens2) << endl; // 输出 6
  return 0;
}
