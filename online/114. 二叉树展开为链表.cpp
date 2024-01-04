#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 它通过递归地先将左右子树分别展开为链表，
// 然后将左子树插入到右子树的位置，最后递归地展开右子树

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void flatten(TreeNode *root) {
  if (!root) {
    return;
  }

  flatten(root->left);
  flatten(root->right);

  TreeNode *right = root->right;

  root->right = root->left;
  root->left = NULL;

  TreeNode *current = root;

  while (current->right)
    current = current->right;

  current->right = right;
}

int main() {
  // 示例用法
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);

  flatten(root);
  return 0;
}
