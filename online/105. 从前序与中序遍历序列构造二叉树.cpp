#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 它通过递归地从前序序列中找到根节点，然后在中序序列中找到根节点的位置，
// 划分出左子树和右子树的序列，再递归构造左右子树。
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  unordered_map<int, int> inorder_map;
  for (int i = 0; i < inorder.size(); ++i) {
    inorder_map[inorder[i]] = i;
  }

  return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1,
               inorder_map);
}

TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                vector<int> &inorder, int inStart, int inEnd,
                unordered_map<int, int> &inorder_map) {
  if (preStart > preEnd || inStart > inEnd) {
    return NULL;
  }

  int rootVal = preorder[preStart];
  TreeNode *root = new TreeNode(rootVal);

  // 在中序序列中找到根节点的位置
  int rootIndex = inorder_map[rootVal];

  // 计算左子树的长度
  int leftSubtreeLength = rootIndex - inStart;

  root->left = build(preorder, preStart + 1, preStart + leftSubtreeLength,
                     inorder, inStart, rootIndex - 1, inorder_map);

  root->right = build(preorder, preStart + leftSubtreeLength + 1, preEnd,
                      inorder, rootIndex + 1, inEnd, inorder_map);

  return root;
}

int main() { return 0; }
