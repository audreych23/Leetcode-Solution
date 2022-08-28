/**
 * Time Complexity: O(k * n log n) // k is the total diagonal m + n - 1, each diagonal has at most n elements
 * Space Complexity: O(n) 
 */
class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    // m x n matrix
    int m { int(mat.size()) };
    int n { int(mat[0].size()) };
    // a row has n starting point of a diagonal
    for (int i {}; i < n; ++i) {
      int x {i}, y {0};
      vector<int> temp_sort;
      while (x < n && y < m) {
        temp_sort.push_back(mat[y][x]);
        y++; x++;
      }
      sort(temp_sort.begin(), temp_sort.end());
      for (auto k {int(temp_sort.size()) - 1}; k >= 0; --k) {
        y--; x--;
        mat[y][x] = temp_sort[k];
      }
    }
    // a column has m - 1 starting point of a diagonal (exclusing mat[0][0])
    for (int j {1}; j < m; ++j) {
      int x {0}, y {j};
      vector<int> temp_sort;
      while (x < n && y < m) {
        temp_sort.push_back(mat[y][x]);
        y++; x++;
      }
      sort(temp_sort.begin(), temp_sort.end());
      for (auto k {int(temp_sort.size()) - 1}; k >= 0; --k) {
        y--; x--;
        mat[y][x] = temp_sort[k];
      }
    }
    return mat;
  }
};
