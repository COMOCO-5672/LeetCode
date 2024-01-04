#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int sumNumbers(TreeNode *root, int currentSum) {
  if (!root) {
    return 0;
  }

  currentSum = currentSum * 10 + root->val;

  if (!root->left && !root->right) {
    return currentSum;
  }

  return sumNumbers(root->left, currentSum) +
         sumNumbers(root->right, currentSum);
}

int sumNumbers(TreeNode *root) { return sumNumbers(root, 0); }

int main() {
  // 示例用法
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  int result = sumNumbers(root);
  return 0;
}
