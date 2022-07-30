/**
 * Time Complexity: O(mn)
 * Space Complexity: O(m + n)
 */
class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m { int(matrix.size()) }; // row size
    int n { int(matrix[0].size()) }; // col size
    vector<int> row(m);
    vector<int> col(n);
    for (int i {}; i < m; ++i) {
      for (int j {}; j < n; ++j) {
        if (!matrix[i][j]) {
          row[i] = 1;
          col[j] = 1;
        }
      }
    }

    for (int i {}; i < m; ++i) {
      for (int j {}; j < n; ++j) {
        if (matrix[i][j] && (row[i] || col[j])) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
