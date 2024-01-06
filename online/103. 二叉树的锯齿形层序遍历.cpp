#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  vector<vector<int>> result;
  if (!root)
    return result;

  queue<TreeNode *> q;
  q.push(root);
  bool leftToRight = true;

  while (!q.empty()) {
    int size = q.size();
    vector<int> level;
    stack<int> s;

    for (int i = 0; i < size; ++i) {
      TreeNode *node = q.front();
      q.pop();

      if (leftToRight) {
        level.emplace_back(node->val);
      } else {
        s.push(node->val);
      }

      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }

    while (!s.empty()) {
      level.emplace_back(s.top());
      s.pop();
    }

    leftToRight = !leftToRight;

    result.emplace_back(level);
  }
  return result;
}

int main() {
  // 示例用法
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  vector<vector<int>> result = zigzagLevelOrder(root);

  cout << "Zigzag level order traversal: " << endl;
  for (const auto &level : result) {
    for (int val : level) {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}
