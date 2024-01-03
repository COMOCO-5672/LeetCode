#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 函数 hasPathSum 采用递归的方式，在每个节点处检查是否存在路径和等于目标和
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode *root, int sum) {
  if (!root)
    return false;

  if (!root->left && !root->right) {
    return sum == root->val;
  }

  return hasPathSum(root->left, sum - root->val) ||
         hasPathSum(root->right, sum - root->val);
}

int main() {
  // 示例用法
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(1);

  int sum = 22;

  bool result = hasPathSum(root, sum);
  return 0;
}
