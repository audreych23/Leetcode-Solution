/**
 * Time complexity: O(mn)
 * Space complexity: O(mn)
 */
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    // m x n matrix
    int m { int(grid.size()) }, n { int(grid[0].size()) };
    // x, y pair (localize everything to this)
    vector<pair<int, int>> dirs {{0,-1}, {1,0}, {0,1}, {-1,0}};
    queue<pair<int, int>> q;
    auto cnt_island {0};

    for (int i {}; i < m; ++i) {
      for (int j {}; j < n; ++j) {
        // grid[i][j] == '1' denotes the possible island
        if (grid[i][j] == '1') {
          q.push(pair<int, int> {j, i});
          grid[i][j] = '2';
          while(!q.empty()) {
            auto curr { q.front() };
            auto y {curr.second}, x {curr.first};
            for (const auto& dir : dirs) {
              auto delta_y {dir.second}, delta_x {dir.first};
              if (y + delta_y < m && y + delta_y >= 0 &&
                  x + delta_x < n && x + delta_x >= 0 &&
                  grid[y + delta_y][x + delta_x] == '1') {
                q.push(pair<int, int> {x + delta_x, y + delta_y});
                // indicates that you won't need to put this piece of land in the queue again
                grid[y + delta_y][x + delta_x] = '2';
              }
            }
            q.pop();
          }
          cnt_island++;
        }
      }
    }
    return cnt_island;
  }

};
/**
 * Idea : you do bfs on all possible starting point, if the bfs stops it means one island.
 * ofcourse all possible starting point will have overlapping island, so we need to indicate if we
 * have processed the land so we will skip it the next time
 */
