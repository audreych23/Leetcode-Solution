/**
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
class Solution {
  int binarySearch(int left, int right, int target, const vector<int> &nums) {
    int mid { int((left + right) / 2) };
    if (left <= right) {
      if (target < nums[mid]) return binarySearch(left, mid - 1, target, nums);
      else if (target > nums[mid]) return binarySearch(mid + 1, right, target, nums);
      else return mid;
    }
    return left;
  }
public:
  int searchInsert(vector<int>& nums, int target) {
    return binarySearch(0, nums.size() - 1, target, nums);
  }
};
