/**
 * Time Complexity : O(n^2)
 * Space Complexity : O(1)
 */
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row_size { 0 };
    for (auto& row : matrix) {
      row_size = row.size();
    }
    int col_size { int(matrix.size()) };
    int mode { 0 }, level { 0 }, ctr { 0 };
    int left { 0 }, right { 1 };
    while (left < right) {
      mode %= 4;
      if (mode == 0) {
        left = ctr, right = row_size - 1 - ctr;
        level = ctr;
        if (col_size - 1 - ctr != ctr) {
          for (int i { left }; i < right; ++i) {
            int x { matrix[level][i] };
            ans.push_back(x);
          }
        }
      } else if (mode == 1) {
        left = ctr, right = col_size - 1 - ctr;
        level = row_size - 1 - ctr;
        if (row_size - 1 - ctr != ctr) {
          for (int i { left }; i < right; ++i) {
            int x { matrix[i][level] };
            ans.push_back(x);
          }
        }
      } else if (mode == 2) {
        left = ctr, right = row_size - 1 - ctr;
        level = col_size - 1 - ctr;
        for (int i { right }; i > left; --i) {
          int x { matrix[level][i] };
          ans.push_back(x);
        }
      } else {
        left = ctr, right = col_size - 1 - ctr;
        level = ctr;
        //if (left == right) break;
        for (int i { right }; i > left; --i) {
          int x { matrix[i][level] };
          ans.push_back(x);
        }
      }
      mode++;
      if (mode == 4) ctr++;
      left = ctr, right = col_size - 1 - ctr; // need to check both
      if (left >= right) break;
      left = ctr, right = row_size - 1 - ctr; // need to check both
    }
    // base case for vertical 1 x n case
    left = ctr, right = row_size - 1 - ctr;
    if (left == right && col_size > row_size) {
      right = col_size - ctr;
      for (int i { left }; i < right; ++i) {
        int x { matrix[i][left] };
        ans.push_back(x);
      }
    }
    // base case for horizontal n x 1 case
    left = ctr, right = col_size - 1 - ctr;
    if (left == right && col_size < row_size) {
      right = row_size - ctr;
      for (int i { left }; i < right; ++i) {
        int x { matrix[left][i] };
        ans.push_back(x);
      }
    } else if (left == right && col_size == row_size) {
      ans.push_back(matrix[left][left]); // 1 x 1 case
    }
    // base case is achievable only when left == right if left > right means no base case
    // left and right for vertical and horizontal case should be different ****
    return ans;
  }
};
