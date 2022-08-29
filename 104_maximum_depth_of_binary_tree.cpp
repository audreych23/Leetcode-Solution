/**
 * Time complexity: O(n)
 * Space complexity: O(n) // system stack
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  void _dfs(TreeNode* root, int& max_depth, int curr_depth) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr && max_depth < curr_depth) {
      max_depth = curr_depth;
    }
    _dfs(root->left, max_depth, curr_depth + 1);
    _dfs(root->right, max_depth, curr_depth + 1);
  }
public:
  int maxDepth(TreeNode* root) {
    int max_depth {};
    _dfs(root, max_depth, 1);
    return max_depth;
  }
};

/**
 * very clean code
 */
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
  }
};
