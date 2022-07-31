class Solution {
  const vector<int> dir_x {-1, 0, 1, 0};
  const vector<int> dir_y {0, 1, 0, -1};
  // curr.second = x // j
  // curr.first = y // i
  void DFS(int k, vector<vector<char>>& board, string word, bool& found, pair<int, int> curr) {
    if (k == word.size() - 1) {
      found = true;
      return;
    }
    for (int i {}; i < 4; ++i) {
      int x { dir_x[i] }; int y { dir_y[i] };
      if ((curr.second + x < board[0].size() && curr.second + x >= 0) &&
        (curr.first + y < board.size() && curr.first + y >= 0) &&
        (board[curr.first + y][curr.second + x] != '@') &&
        (board[curr.first + y][curr.second + x] == word[k + 1])) {
          char temp { board[curr.first + y][curr.second + x] };
          board[curr.first + y][curr.second + x] = '@';
          auto new_c { curr };
          new_c.first = new_c.first + y; new_c.second = new_c.second + x;
          DFS(k + 1, board, word, found, new_c);
          board[curr.first + y][curr.second + x] = temp;
          if (found == true) return;
      }
    }
    return;
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    vector<pair<int,int>> v;
    // find starting point
    for (int i {}; i < board.size(); ++i) {
      for (int j {}; j < board[0].size(); ++j) {
        if (board[i][j] == word[0]) {
          v.push_back(pair<int, int> {i, j});
        }
      }
    }

    if (v.empty()) return false;
    bool found { false };
    for (const auto& c: v) {
      char temp { board[c.first][c.second] };
      board[c.first][c.second] = '@';
      DFS(0, board, word, found, c);
      board[c.first][c.second] = temp;
      if (found == true) break;
    }
    return found;
  }
};
