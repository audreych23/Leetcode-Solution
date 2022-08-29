/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 */
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n) );
    for (int i {}; i < m; ++i) {
      for (int j {}; j < n; ++j) {
        if (!i || !j) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[i - 1][j - 1];
  }
};
