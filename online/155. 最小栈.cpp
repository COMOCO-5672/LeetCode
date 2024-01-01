#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
  MinStack() {}

  void push(int x) {
    // 将元素推入元素栈
    dataStack.push(x);

    if (minStack.empty() || x <= minStack.top()) {
      minStack.push(x);
    }
  }

  void pop() {
    if (!dataStack.empty()) {
      // 如果元素栈不为空，弹出元素
      int top = dataStack.top();
      dataStack.pop();

      // 如果弹出的元素是最小元素，也需要更新最小元素栈
      if (top == minStack.top()) {
        minStack.pop();
      }
    }
  }

  int top() {
    if (!dataStack.empty()) {
      // 返回元素栈的栈顶元素
      return dataStack.top();
    }
    return -1;
  }

  int getMin() {
    if (!minStack.empty()) {
      // 返回最小元素栈的栈顶元素
      return minStack.top();
    }
    return -1;
  }

private:
  stack<int> dataStack; // 存储元素
  stack<int> minStack;  // 存储当前栈中的最小元素
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() { return 0; }
