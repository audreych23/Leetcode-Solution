 /**
 * Time Complexity: O(|V| + |E|)
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
private:
    void DFS(TreeNode* root, int root_leaf_val, int& sum) {
        if (root->left == nullptr  && root->right == nullptr) {
            sum += root_leaf_val * 10 + root->val;
            return; 
        }

        if (root->left != nullptr) {
            DFS(root->left, root_leaf_val * 10 + root->val, sum);
        }
        if (root->right != nullptr) {
            DFS(root->right, root_leaf_val * 10 + root->val, sum);
        }
        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        DFS(root, 0, sum);
        return sum; 
    }
};