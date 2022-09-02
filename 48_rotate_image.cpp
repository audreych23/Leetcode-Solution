/**
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 * Idea : you swap it like normally brute force.
 * diaphgram link - https://imgur.com/wHRwQX7.jpg
 */
class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    // n x n matrix
    auto n { int(matrix.size()) };
    // l denotes level of cube, start and end denotes how many elements we need to swap in one level
    int l {}, start {}, end {n};
    while (start < end) {
      for(int i {start}; i < end - 1; ++i) {
        // 4 elements swap
        auto store { matrix[l][i] };
        matrix[l][i] = matrix[n - 1 - i][l];
        matrix[n - 1 - i][l] = matrix[n - 1 - l][n - 1 - i];
        matrix[n - 1 - l][n - 1 - i] = matrix[i][n - 1 - l];
        matrix[i][n - 1 - l] = store;
      }
      l++; start++; end--;
    }
  }
};
