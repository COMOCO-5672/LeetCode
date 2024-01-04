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

int countNodes(TreeNode *root) {
  if (!root) {
    return 0;
  }

  // 计算左右子树的高度
  int leftHeight = 0, rightHeight = 0;
  TreeNode *left = root, *right = root;
  while (left) {
    leftHeight++;
    left = left->left;
  }

  while (right) {
    rightHeight++;
    right = right->right;
  }

  // 如果左右子树高度相同，说明左子树是满二叉树，可以直接计算节点数
  if (leftHeight == rightHeight) {
    return (1 << leftHeight) - 1;
  }
  // 如果左右子树高度不同，说明右子树是满二叉树，递归计算节点数
  return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
  // 示例用法
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);

  int result = countNodes(root);
  cout << "Number of nodes in the complete binary tree: " << result << endl;
  return 0;
}
