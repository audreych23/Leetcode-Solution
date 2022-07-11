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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* temp1 { list1 };
    ListNode* temp2 { list2 };
    ListNode* result { new ListNode() }; // dummy head
    ListNode* result_temp { result };
    while(temp1 != nullptr && temp2 != nullptr) {
      if (temp1->val < temp2->val) {
        result_temp->next = temp1;
        temp1 = temp1->next;
      } else {
        result_temp->next = temp2;
        temp2 = temp2->next;
      }
      result_temp = result_temp->next;
    }

    while (temp1 != nullptr) {
      result_temp->next = temp1;
      temp1 = temp1->next;
      result_temp = result_temp->next;
    }

    while (temp2 != nullptr) {
      result_temp->next = temp2;
      temp2 = temp2->next;
      result_temp = result_temp->next;
    }

    return result;
  }
};
