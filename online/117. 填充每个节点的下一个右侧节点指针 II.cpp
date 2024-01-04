#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 它通过层次遍历的方式，使用队列来处理每一层的节点，
// 然后在遍历每一层的节点时，将它们的 next 指针连接起来。
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root) {

  if (!root) {
    return NULL;
  }

  // 使用队列进行层次遍历
  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = q.size();

    // 遍历当前层的节点
    for (int i = 0; i < levelSize; ++i) {

      Node *node = q.front();
      q.pop();

      if (i < levelSize - 1) {
        node->next = q.front();
        std::cout << "next:" << node->next->val << std::endl;
      }

      // 将当前层的左右结点送入队列，下次循环时遍历下一层
      if (node->left) {
        std::cout << "left push:" << node->left->val << std::endl;
        q.push(node->left);
      }
      if (node->right) {
        std::cout << "right push:" << node->right->val << std::endl;
        q.push(node->right);
      }
    }
  }
  return root;
}

int main() {
  // 示例用法
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(7);

  connect(root);
  return 0;
}
