/**
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int IMAX { numeric_limits<int>::max() };
    int k { int(nums.size()) };
    bool pair { false };
    for (int i {}; i < int(nums.size() - 1); ++i) {
      if (!pair && (nums[i] == nums[i + 1])) {
        pair = true;
      } else if (pair && (nums[i] == nums[i + 1])) {
        // change the current number above the question constraints so we have at most 2 of the same number in array
        nums[i] = IMAX;
        k--;
      } else if (pair && (nums[i] != nums[i + 1])) {
        pair = false;
      }
    }
    sort(nums.begin(), nums.end()); // modify the array so it has its relative order
    return k;
  }
};
// add O(n) solution
