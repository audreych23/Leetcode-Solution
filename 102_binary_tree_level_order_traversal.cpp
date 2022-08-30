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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    // pair of val and level atm
    queue<pair<TreeNode*, int>> q;
    vector<int> node_same_level;

    int prev_level {};
    q.push(pair<TreeNode*, int> {root, 0});
    while(!q.empty()) {
      auto front_pair = q.front();
      if (front_pair.first->left != nullptr) q.push({front_pair.first->left, front_pair.second + 1});
      if (front_pair.first->right != nullptr) q.push({front_pair.first->right, front_pair.second + 1});
      if (prev_level != front_pair.second) {
        ans.push_back(node_same_level);
        node_same_level.clear();
      }
      node_same_level.push_back(front_pair.first->val);
      prev_level = front_pair.second;
      q.pop();
    }
    // final push
    ans.push_back(node_same_level);
    return ans;
  }
};
