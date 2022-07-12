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
class Compare {
public:
  bool operator() (ListNode* a, ListNode* b) {
    return (b->val < a->val ? 1 : 0);
  }
};
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    for (auto curr_idx : lists) {
      if(curr_idx != nullptr) {
        pq.push(curr_idx);
      }
    }
    ListNode* result { new ListNode() }; // dummy head
    ListNode* temp_result { result };

    while (!pq.empty()) {
      ListNode* curr { pq.top() };
      temp_result->next = curr;
      pq.pop();
      if (curr->next != nullptr) {
        pq.push(curr->next);
      }
      temp_result = temp_result->next;
    }

    return result->next;
  }
};
