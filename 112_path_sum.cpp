/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
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
  void dfs(TreeNode* root, int targetSum, int curr_sum, bool& is_reachable) {
    if (curr_sum == targetSum && root->left == nullptr && root->right == nullptr) {
      is_reachable = true;
      return;
    }
    if (root->left == nullptr && root->right == nullptr) return;
    if (root->left != nullptr && !is_reachable)
      dfs(root->left, targetSum, curr_sum + root->left->val, is_reachable);
    if (root->right != nullptr && !is_reachable)
      dfs(root->right, targetSum, curr_sum + root->right->val, is_reachable);
  }
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    bool is_reachable = false;
    dfs(root, targetSum, root->val, is_reachable);
    return is_reachable;
  }
};
