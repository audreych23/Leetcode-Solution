/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
 // very bad solution of it, will come back and find a better method
class Solution {
    void DFS(TreeNode* root, ListNode* head, deque<int> &dq, bool &is_found) {
        if (is_found) return;
        if (root == nullptr) {
            // compare path with linked list
            
            vector<int> path;
            deque<int> dq_temp = dq;
            while (!dq_temp.empty()) {
                int val = dq_temp.front();
                dq_temp.pop_front();
                path.push_back(val);
            }
            for (int i = 0; i < path.size(); ++i) {
                // use the slowest compare string algorithm
                // mayeb optimize later using KKN ? string algo (O (n + m))
                ListNode* current = head;
                int j = i;
                while (current != nullptr && j < path.size() && current->val == path[j]) {
                    j++;
                    current = current->next;
                }
                if (current == nullptr) {
                    is_found = true;
                    break;
                }
            }
            return;
        }
        dq.push_back(root->val);
        
        DFS(root->left, head, dq, is_found);
        DFS(root->right, head, dq, is_found);
        dq.pop_back();
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        deque<int> dq;
        bool is_found = false;
        DFS(root, head, dq, is_found);
        return is_found;
    }
};