/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
  vector<int> preorderTraversal(TreeNode *root) {

    vector<int> result;
    inorderHelper(root, result);
    return result;
  }

private:
  void inorderHelper(TreeNode *node, vector<int> &result) {
    if (!node) {
      return;
    }

    result.push_back(node->val);
    inorderHelper(node->left, result);
    inorderHelper(node->right, result);
  }
};
// @lc code=end
