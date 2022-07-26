/**
 * Time Complexity : O(log n)
 * Space Complexity : O(1)
 */
class Solution {
  // to find the pivot : important observation that all the elements on the left of the pivot is larger
  // than right of pivot including pivot
  int binarySearchPivot (int left, int right, const vector<int>& nums) {
    int mid { int((left + right) / 2) };
    if (left <= right) {
      if (nums[right] < nums[mid]) {
        return binarySearchPivot(mid + 1, right, nums);
      } else if (nums[right] > nums[mid]) {
        return binarySearchPivot(left, mid, nums);
      } else {
        return mid;
      }
    }
    return mid;
  }
  // normal binary search to find the index of target
  int binarySearch (int left, int right, int target, const vector<int> &nums) {
    int mid { int((left + right) / 2) };
    if (left <= right) {
      if (target < nums[mid]) {
        return binarySearch(left, mid - 1, target, nums);
      } else if (target > nums[mid]) {
        return binarySearch(mid + 1, right, target, nums);
      } else {
        return mid;
      }
    }
    return -1;
  }
public:
  int search(vector<int>& nums, int target) {
    auto pivot { binarySearchPivot(0, nums.size() - 1, nums) };
    // possible area where the target would be located
    if (target <= nums[nums.size() - 1] && target >= nums[pivot]) {
      return binarySearch(pivot, nums.size() - 1, target, nums);
    } else if (pivot > 0 && target >= nums[0] && target <= nums[pivot - 1]) {
      return binarySearch(0, pivot - 1, target, nums);
    } else {
      return -1;
    }
  }
};
