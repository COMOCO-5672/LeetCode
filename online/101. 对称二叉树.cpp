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

bool isSymmetric(TreeNode *root) {
  // 递归判断左右子树是否对称
  return isMirror(root, root);
}

// 释放二叉树内存
void deleteTree(TreeNode *root) {
  if (!root) {
    return;
  }

  // 递归释放左右子树
  deleteTree(root->left);
  deleteTree(root->right);

  // 释放当前节点
  delete root;
}

bool isMirror(TreeNode *left, TreeNode *right) {
  if (!left && !right)
    return true;

  if (!left || !right)
    return false;

  if (left->val != right->val)
    return false;

  return isMirror(left->left, right->right) &&
         isMirror(left->right, right->left);
}

int main() {
  // 示例用法
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  cout << "Is the tree symmetric? " << (isSymmetric(root) ? "Yes" : "No")
       << endl;

  // 释放内存
  deleteTree(root);
  return 0;
}
