/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    ListNode* curr { head };
    while(curr->next) {
      ListNode* next { curr->next };
      if (curr->val == next->val) {
        curr->next = next->next;
        delete next;
      } else {
        curr = curr->next;
      }
    }
    return head;
  }
};
