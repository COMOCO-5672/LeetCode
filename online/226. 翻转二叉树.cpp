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

TreeNode *invertTree(TreeNode *root) {
  // 递归结束条件，如果当前节点为空，直接返回
  if (!root)
    return NULL;

  // 交换当前节点的左右子树
  swap(root->left, root->right);

  // 递归翻转左右子树
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

// 打印二叉树（中序遍历）
void printTree(TreeNode *root) {
  if (!root) {
    return;
  }

  // 左子树
  printTree(root->left);

  // 当前节点
  cout << root->val << " ";

  // 右子树
  printTree(root->right);
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

int main() {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);

  cout << "Original Tree: ";
  printTree(root);
  cout << endl;

  TreeNode *invertedRoot = invertTree(root);

  cout << "Inverted Tree: ";
  printTree(invertedRoot);
  cout << endl;

  // 释放内存
  deleteTree(root);
  deleteTree(invertedRoot);

  return 0;
}
