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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* curr_1 = l1;
    ListNode* curr_2 = l2;
    ListNode* ans = new ListNode(); // dummy head
    ListNode* temp = ans;
    int carry = 0;

    while(curr_1 != nullptr && curr_2 != nullptr) {
      int val = (curr_1->val + curr_2->val + carry) % 10;
      if (curr_1->val + curr_2->val + carry >= 10) carry = 1;
      else carry = 0;
      temp->next = new ListNode(val);
      curr_1 = curr_1->next;
      curr_2 = curr_2->next;
      temp = temp->next;
    }

    while(curr_1 != nullptr) {
      temp->next = new ListNode((curr_1->val + carry) % 10);
      if (curr_1->val + carry >= 10) carry = 1;
      else carry = 0;
      curr_1 = curr_1->next;
      temp = temp->next;
    }

    while(curr_2 != nullptr) {
      temp->next = new ListNode((curr_2->val + carry) % 10);
      if (curr_2->val + carry >= 10) carry = 1;
      else carry = 0;
      curr_2 = curr_2->next;
      temp = temp->next;
    }

    if (carry == 1) {
      temp->next = new ListNode(1);
      temp = temp->next;
    }
    return ans->next;
  }
};
