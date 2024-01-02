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

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (!p && !q)
    return true;

  if (!p || !q)
    return false;

  if (p->val != q->val)
    return false;

  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
  // 示例用法
  TreeNode *p = new TreeNode(1);
  p->left = new TreeNode(2);
  p->right = new TreeNode(3);

  TreeNode *q = new TreeNode(1);
  q->left = new TreeNode(2);
  q->right = new TreeNode(3);

  cout << "Are the trees the same? " << (isSameTree(p, q) ? "Yes" : "No")
       << endl;

  // 释放内存
  delete p->left;
  delete p->right;
  delete p;
  delete q->left;
  delete q->right;
  delete q;
  return 0;
}
