/**
 * Time Complexity: O(n)
 * Space Complexity: O(n) // system stack?
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
  void _inorderTraversal(TreeNode* root, vector<int>& ans) {
    if (root) {
      _inorderTraversal(root->left, ans);
      ans.push_back(root->val);
      _inorderTraversal(root->right, ans);
    }
  }
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    _inorderTraversal(root, ans);
    return ans;
  }
};

// add morris traversal and iterative solution
