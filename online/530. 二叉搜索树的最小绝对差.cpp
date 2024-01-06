#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// 对于二叉搜索树，中序遍历的结果是有序的。
// 因此，中序遍历该二叉搜索树，计算相邻节点值的差，找到最小的差值即可
using namespace std;

// 二叉树节点的定义
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}
};

void inOrderTraversal(TreeNode *root, vector<int> &vals) {
  if (!root) {
    return;
  }

  inOrderTraversal(root->left, vals);
  vals.emplace_back(root->val);
  inOrderTraversal(root->right, vals);
}

int getMinimumDifference(TreeNode *root) {
  vector<int> vals;
  inOrderTraversal(root, vals);

  int minDiff = INT_MAX;
  for (int i = 1; i < vals.size(); ++i) {
    minDiff = std::min(minDiff, vals[i] - vals[i - 1]);
  }

  return minDiff;
}

int main() {
  // 示例用法
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(2);

  int result = getMinimumDifference(root);

  cout << "Minimum absolute difference: " << result << endl;
  return 0;
}
