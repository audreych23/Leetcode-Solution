/**
 * Time complexity: O(n)
 * Space complexity: O(n)
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
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    if (root == nullptr) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int n { int(q.size()) }; // can have nullptr
      double avg_per_level {};
      double total_node_in_level { double(q.size()) }; // without nullptr
      for (int i {}; i < n; ++i) {
        auto front_node {q.front()}; q.pop();
        if (front_node != nullptr) {
          q.push(front_node->left);
          q.push(front_node->right);
          avg_per_level += front_node->val;
        } else {
          total_node_in_level--;
        }
      }
      // check if it actually has at least a node in this level
      if (total_node_in_level) {
        avg_per_level /= total_node_in_level;
        ans.push_back(avg_per_level);
      }
    }
    return ans;
  }
};
