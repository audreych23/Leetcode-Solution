/**
 * Time Complexity: O(mn)
 * Space Complexity: O(1) // modify input array
 */
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int m {int(grid.size())};
    int n {int(grid[0].size())};
    for(int i {}; i < m; ++i) {
      for (int j {}; j < n; ++j) {
        if (!i && j) {
          grid[i][j] += grid[i][j - 1];
        } else if (i && !j) {
          grid[i][j] += + grid[i - 1][j];
        } else if(i && j) {
          grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
      }
    }
    return grid[m - 1][n - 1];
  }
};

// maybe try using the O(n) space Complexity?
