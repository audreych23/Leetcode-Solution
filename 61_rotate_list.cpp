/**
 * Time Complexity : O(n)
 * Space Complexity : O(1)
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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return head;
    int n {};
    // find size of list
    for (ListNode* temp { head }; temp != nullptr; temp = temp->next) {
      n++;
    }
    k %= n;
    ListNode* end {};
    ListNode* rotate_pivot {};
    int cnt {};
    if (k == n) return head;
    for (ListNode* temp { head }; temp != nullptr; temp = temp->next) {
      if (temp->next == nullptr) { end = temp; }
      if (n - k - 1 == cnt) {
        rotate_pivot = temp;
      }
      cnt++;
    }
    end->next = head;
    head = rotate_pivot->next;
    rotate_pivot->next = nullptr;
    return head;
  }
};
/**
 * idea : find the whole size of the linked list to find if we can modulo the rotation if more than the size
 * and use it to find where is the rotation pivot to connect to nullptr and the next element after that will be
 * the head, which is (n - k)
 * end will always be connected to the old head
 */
