/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> table;
    for (const auto& num: nums) {
      table[num]++;
    }
    auto max {0};
    auto ans {0};
    for (const auto& element: table) {
      if (max < element.second) {
        ans = element.first;
        max = element.second;
      }
    }
    return ans;
  }
};
