/**
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    // m x n matrix
    int m { int(obstacleGrid.size()) };
    int n { int(obstacleGrid[0].size()) };
    // special case when exit is blocked by obstacle
    if (obstacleGrid[m - 1][n - 1] == 1) return 0;
    // to modify and check the matrix easily, so no need for extra space
    for (int i {}; i < m; ++i) {
      for (int j {}; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) {
          obstacleGrid[i][j] = -1;
        }
      }
    }

    for (int i {}; i < m; ++i) {
      for (int j {}; j < n; ++j) {
        if (obstacleGrid[i][j] == -1) continue;
        if (!i && !j) {
          obstacleGrid[i][j] = 1;
        } else if (!i && j) {
          if (obstacleGrid[i][j - 1] != -1) {
            obstacleGrid[i][j] = obstacleGrid[i][j - 1];
          }
        } else if (i && !j) {
          if (obstacleGrid[i - 1][j] != -1) {
            obstacleGrid[i][j] = obstacleGrid[i - 1][j];
          }
        } else {
          if (obstacleGrid[i - 1][j] != -1 && obstacleGrid[i][j - 1] != -1) {
            obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
          } else if (obstacleGrid[i - 1][j] != -1) {
            obstacleGrid[i][j] = obstacleGrid[i - 1][j];
          } else if (obstacleGrid[i][j - 1] != -1) {
            obstacleGrid[i][j] = obstacleGrid[i][j - 1];
          }
        }
      }
    }

    return obstacleGrid[m - 1][n - 1];
  }
};
