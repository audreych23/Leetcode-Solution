/**
 * Time Complexity: O(n) size of the linked list
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
  ListNode* swapPairs(ListNode* head) {
    // special case when size == 0 or size == 1
    if (head == nullptr || head->next == nullptr) return head;
    auto prev { head };
    auto now { head->next };
    auto previous { prev };
    while (now != nullptr) {
      auto next { now->next };
      // swap happens here
      now->next = prev;
      // assign the head to the swapped node (needs to do it first time)
      if (head == prev) head = now;
      else {
        // this is to connect to the previous swapped nodes
        // this happens second time onwards
        previous->next = now;
        previous = prev; // assign previous to be connected later (previous->next equals something next iter)
      }
      // go to the new 2 nodes
      prev = next;
      if (prev != nullptr) {
        now = prev->next;
      } else {
        // size is even case (prev will be nullptr)
        previous->next = nullptr;
        break;
      }
    }
    // size is odd case (escape from loop by the initial while condition)
    if (now == nullptr) {
      previous->next = prev;
    }
    return head;
  }
};
/**
 * Explanation : you can only connect to the next 2 nodes when the 2 next nodes finish swapping
 * prev and now is for swapping, next is to go to the next 2 nodes before connecting them and after swap
 * (since next will be gone after swap)
 * previous is for the previous 2 nodes to connect to the just finished 2 swapping nodes
 */
