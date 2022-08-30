/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 * store additional variable like a level in the pair
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

/**
 * A cleaner solution, it has the same idea as putting a null as an indication when should we go to next lvl
 * ref-link: (putting this here because the answers discussion are interesting)
 * https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33443/C%2B%2B-solution-using-only-one-queue-use-a-marker-NULL
 * the answer on this discussion is where the idea came from
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
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
      int n = q.size(); // how many elements do in one level at this moment
      vector<int> node_same_level;
      // the queue at this point will only store all the elements in a level
      // make a vector for this level while pushing children into queue
      for (int i {}; i < n; ++i) {
        auto front = q.front(); q.pop();
        if (front != nullptr) {
          node_same_level.push_back(front->val);
          q.push(front->left);
          q.push(front->right);
        }
      }
      // important because all children can be nullptr
      if (node_same_level.size() > 0)
        ans.push_back(node_same_level);
    }
    return ans;
  }
};
