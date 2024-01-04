#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode *root) {
  vector<int> result;

  if (!root) {
    return result;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();

    // 遍历当前层的节点
    for (int i = 0; i < size; ++i) {
      TreeNode *node = q.front();
      q.pop();

      // 只保留每层最右侧的节点值
      if (i == size - 1) {
        result.push_back(node->val);
      }

      // 将下一层的节点队列
      if (node->left) {
        q.push(node->left);
      }

      if (node->right) {
        q.push(node->right);
      }
    }
  }
  return result;
}

int main() { return 0; }
