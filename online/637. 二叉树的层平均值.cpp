#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}
};

vector<double> averageOfLevels(TreeNode *root) {
  vector<double> averages;
  if (!root) {
    return averages;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    double sum = 0.0;

    // 遍历当前层节点
    for (int i = 0; i < size; ++i) {
      TreeNode *node = q.front();
      q.pop();

      // 累加当前层的节点值
      sum += node->val;

      // 将下一层的节点加入队列
      if (node->left) {
        q.push(node->left);
      }

      if (node->right) {
        q.push(node->right);
      }
    }

    // 计算当前层的平均值并加入结果数组
    averages.push_back(sum / size);
  }
  return averages;
}

int main() {
  // 示例用法
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  vector<double> result = averageOfLevels(root);

  cout << "Average values of each level: ";
  for (double avg : result) {
    cout << avg << " ";
  }
  cout << endl;
  return 0;
}