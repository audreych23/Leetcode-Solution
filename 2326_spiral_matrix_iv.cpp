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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int> (n));
    	int col_it = m - 1;
        int row_it = n - 1;
        int i = 0;
        int j = 0;
        ListNode* temp = head;
        while (col_it > 0 && row_it > 0) {
            for (int k = 0; k < row_it; ++k) {
                if (temp != nullptr) {
                    cout << temp->val;
                    mat[i][j++] = temp->val;
                    temp = temp->next;
                } else {
                    mat[i][j++] = -1;
                }
                 
            }
            
            for (int k = 0; k < col_it; ++k) {
                if (temp != nullptr) {
                    mat[i++][j] = temp->val;
                    temp = temp->next;
                } else {
                    mat[i++][j] = -1;
                }
                 
            }
            
            for (int k = 0; k < row_it; ++k) {
                if (temp != nullptr) {
                    mat[i][j--] = temp->val;
                    temp = temp->next;
                } else {
                    mat[i][j--] = -1;
                }
                 
            }
            
            for (int k = 0; k < col_it; ++k) {
                if (temp != nullptr) {
                    mat[i--][j] = temp->val;
                    temp = temp->next;
                } else {
                    mat[i--][j] = -1;
                }
                 
            }
            col_it -= 2;
            row_it -= 2;
            i += 1;
            j += 1;
            
        }
        
        // case when one of them is 0 or both are 0
        if (row_it == 0) {
            col_it += 1;
            while (col_it--) {
                if (temp != nullptr) {
                    mat[i++][j] = temp->val;
                    temp = temp->next;
                } else {
                    mat[i++][j] = -1;
                }
            }
        }
        
        if (col_it == 0) {
            row_it += 1;
            while (row_it--) {
                if (temp != nullptr) {
                    mat[i][j++] = temp->val;
                    temp = temp->next;
                } else {
                    mat[i][j++] = -1;
                }
            }
        }
        return mat;
        
    }
};