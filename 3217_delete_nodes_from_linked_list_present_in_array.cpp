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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for (const auto& num: nums) {
            s.insert(num);
        }
        
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr) {
            if (s.find(temp->val) != s.end()) {
                if (prev == nullptr) {
                    head = temp->next;
                    delete temp;
                    temp = head;
                } else {
                    ListNode* nxt = temp->next;
                    prev->next = nxt;
                    delete temp;
                    temp = nxt;
                }
            } else {
                temp = temp->next;
                if (prev != nullptr)
                    prev = prev->next;
                else 
                    prev = head;
            }
        }
        return head;
    }
};