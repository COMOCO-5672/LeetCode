#include <iostream>
#include <vector>
#include <queue>
#include <list>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();

    int minDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        std::queue<std::pair<TreeNode *, int> > que;
        que.emplace(root, 1);
        while (!que.empty()) {
            TreeNode *node = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }
            if (node->left != nullptr) {
                que.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                que.emplace(node->right, depth + 1);
            }
        }

        return 0;
    }

};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}


int main()
{
    return 0;
}