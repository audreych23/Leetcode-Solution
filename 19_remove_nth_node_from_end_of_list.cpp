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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> store;
    while(head != nullptr) {
      store.push_back(head);
      head = head->next;
    }

    if (store.size() - 1 - n == -1) {
      // deleting head
      auto curr = store[0];
      auto head = curr->next;
      delete curr;
      return head;
    }
    auto curr = store[int(store.size()) - 1 - n]; // this is the stored node before the node that we want to delete
    auto nxt = curr->next->next;
    delete curr->next;
    curr->next = nxt;
    return store[0];
  }
};
