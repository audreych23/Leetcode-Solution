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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        ListNode* temp = head;
        int num_nodes = 0;
        while (temp != nullptr) {
            num_nodes++;
            temp = temp->next;
        }
        int r = num_nodes % k; // remainder means that there should be this many nodes with an extra 1 node inside the group
        int div = num_nodes / k; // how many nodes before splitting
        temp = head;
        
        int count = 0;
        int i = 1; 
        int i_counter = 0;
        if (r == 0) i = 0;
        if (num_nodes >= k) {
            while (temp != nullptr) {
                ListNode* next = temp->next;
                if (count == 0) {
                    res.push_back(temp);
                }
                count++;
                if (count == div + i) {
                    count = 0;
                    temp->next = nullptr;
                    i_counter++;
                    if (i_counter == r) i = 0;
                }
                temp = next;
            }
        } else {
            while (temp != nullptr) {
                ListNode* next = temp->next;
                res.push_back(temp);
                temp->next = nullptr;
                count++;
                temp = next;
            }
            
            while (count < k) {
                res.push_back(nullptr);
                count++;
            } 
        }
        return res;
    }
};