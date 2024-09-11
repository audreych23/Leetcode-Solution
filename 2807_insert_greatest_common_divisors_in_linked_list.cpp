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
    int gcd(int a, int b) {
        if (b == 0) return a;
        else {
            return gcd(b, a % b);
        }
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head->next;
        ListNode* prev = head;
        while(current != nullptr) {
            ListNode* new_node = new ListNode(gcd(prev->val, current->val));
            prev->next = new_node;
            new_node->next = current;
            prev = current;
            current = current->next;            
        }
        return head;
    }
};