#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 它通过递归地从后序序列中找到根节点，
// 然后在中序序列中找到根节点的位置，划分出左子树和右子树的序列，再递归构造左右子树。

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  unordered_map<int, int> inorder_map;
  for (int i = 0; i < inorder.size(); ++i) {
    inorder_map[inorder[i]] = i;
  }

  return build(inorder, 0, inorder.size() - 1, postorder, 0,
               postorder.size() - 1, inorder_map);
}

TreeNode *build(vector<int> &inorder, int inStart, int inEnd,
                vector<int> &postorder, int postStart, int postEnd,
                unordered_map<int, int> &inorder_map) {
  // 递归结束条件：中序序列或后序序列为空
  if (inStart > inEnd || postStart > postEnd) {
    return NULL;
  }

  // 后序序列的最后一个节点是当前子树的根节点
  int rootVal = postorder[postEnd];
  TreeNode *root = new TreeNode(rootVal);

  // 在中序序列中找到根节点的位置
  int rootIndex = inorder_map[rootVal];

  // 计算右子树的长度
  int rightSubtreeLength = inEnd - rootIndex;

  // 递归构造左右子树
  root->left = build(inorder, inStart, rootIndex - 1, postorder, postStart,
                     postEnd - rightSubtreeLength - 1, inorder_map);
  root->right = build(inorder, rootIndex + 1, inEnd, postorder,
                      postEnd - rightSubtreeLength, postEnd - 1, inorder_map);

  return root;
}

int main() { return 0; }
