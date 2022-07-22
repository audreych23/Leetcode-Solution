/**
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 */
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    queue<int> q; // store the index of the removed occurence
    for (int i {}; i < int(nums.size()); ++i) {
      if (nums[i] == val) {
        q.push(i);
      }
    }

    auto sz { int(nums.size() - q.size()) };
    auto k {sz};
    while (!q.empty() && q.front() < sz) {
      // this is for the case if the nums[k] is one of the occurence I removed
      if (val == nums[k]) { k++; continue; }
      nums[q.front()] = nums[k];
      k++;
      q.pop();
    }
    return sz;
  }
};
