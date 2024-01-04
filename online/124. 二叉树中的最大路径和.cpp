#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// maxPathSum 函数采用递归的方式，在每个节点处计算包含该节点的最大路径和，
// 同时更新全局的最大路径和
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int maxPathSum(TreeNode *root, int &maxSum) {
  if (!root) {
    return 0;
  }

  int leftSum = max(0, maxPathSum(root->left, maxSum));
  int rightSum = max(0, maxPathSum(root->right, maxSum));

  int currentPathSum = leftSum + rightSum + root->val;

  maxSum = max(maxSum, currentPathSum);

  return max(leftSum, rightSum) + root->val;
}

int maxPathSum(TreeNode *root) {
  int maxSum = INT_MIN;
  maxPathSum(root, maxSum);
  return maxSum;
}

int main() {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(2);
  root->right = new TreeNode(10);
  root->left->left = new TreeNode(20);
  root->left->right = new TreeNode(1);
  root->right->right = new TreeNode(-25);
  root->right->right->left = new TreeNode(3);
  root->right->right->right = new TreeNode(4);

  int result = maxPathSum(root);
  cout << "Maximum path sum in the binary tree: " << result << endl;
  return 0;
}
