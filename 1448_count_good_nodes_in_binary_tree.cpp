/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 * invariant : a node will be good only if all the previous nodes are smaller than the current nodes
 * so we can pass down the maximum and compare to the current node
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
  void dfs(TreeNode* curr, int curr_max, int& cnt) {
    if (curr == nullptr) return;
    if (curr_max <= curr->val) {
      curr_max = curr->val;
      cnt++;
    }
    dfs(curr->left, curr_max, cnt);
    dfs(curr->right, curr_max, cnt);
    return;
  }
public:
  int goodNodes(TreeNode* root) {
    int cnt {};
    dfs (root, -10001, cnt);
    return cnt;
  }
};
