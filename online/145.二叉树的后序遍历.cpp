/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
  }

private:
  void inorderHelper(TreeNode *node, vector<int> &result) {
    if (!node) {
      return;
    }

    inorderHelper(node->left, result);
    inorderHelper(node->right, result);
    result.push_back(node->val);
  }
};
// @lc code=end
