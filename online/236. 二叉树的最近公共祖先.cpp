#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// 如果左右子树分别找到了不为空的节点，说明当前节点就是最近的公共祖先

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestore(TreeNode *root, TreeNode *p, TreeNode *q) {
  // 如果树为空， 或者找到了其中一个节点，直接返回当前节点
  if (!root || root == p || root == q) {
    return root;
  }

  // 在左右子树中分辨寻找公共祖先
  TreeNode *left = lowestCommonAncestore(root->left, p, q);
  TreeNode *right = lowestCommonAncestore(root->right, p, q);

  // 如果左右子树分辨找到了不为空的节点， 说明当前节点是最新的公共祖先
  if (left && right) {
    return root;
  }

  return left ? left : right;
}

int main() {

  // 示例用法
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  TreeNode *p = root->left;
  TreeNode *q = root->right;

  TreeNode *result = lowestCommonAncestore(root, p, q);

  cout << "The lowest common ancestor is: " << result->val << endl;

  return 0;
}
