/**
 * Time Complexity: O(log m + log n)
 * Space Complexity: O(1)
 */
class Solution {
  int rowBinarySearch(vector<vector<int>>& matrix, int target, int left, int right) {
    int mid { int((left + right) / 2) };
    if (left <= right) {
      // handling when to return mid and edge cases such as mid points to the last row / last element
      if (mid != matrix.size() - 1 && matrix[mid + 1][0] > target && matrix[mid][0] <= target) return mid;
      else if (mid == matrix.size() - 1 && matrix[mid][0] >= target) return mid;

      if (matrix[mid][0] > target) return rowBinarySearch(matrix, target, left, mid - 1);
      else if (matrix[mid][0] < target) return rowBinarySearch(matrix, target, mid + 1, right);
      else return mid;
    }
    return mid; // this case won't happen I think;
  }
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m { int(matrix.size() - 1) };
    int n { int(matrix[0].size() - 1) };
    int r { rowBinarySearch(matrix, target, 0, matrix.size() - 1) };
    return binary_search(matrix[r].begin(), matrix[r].end(), target);
  }
};
