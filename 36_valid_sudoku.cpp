/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2))
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // hash[x][y] : keep track of x row and if number y has been put or not
        // x denotes which row/col/sub_boxes is it 
        // y denotes the number from 1 to 9 in sudoku
        vector<vector<int>> hash_row(board.size(), vector<int> (board[0].size()));
        vector<vector<int>> hash_col(board.size(), vector<int> (board[0].size()));
        vector<vector<int>> hash_box(board.size(), vector<int> (board[0].size()));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') continue;
                int digit = board[i][j] - '0';
                int convert_to_box = 0;
                if (0 <= i && i < 3) {
                    if (0 <= j && j < 3) {
                        convert_to_box = 0;
                    } else if (3 <= j && j < 6) {
                        convert_to_box = 1;
                    } else {
                        convert_to_box = 2;
                    }
                } else if (3 <= i && i < 6) {
                    if (0 <= j && j < 3) {
                        convert_to_box = 3;
                    } else if (3 <= j && j < 6) {
                        convert_to_box = 4;
                    } else {
                        convert_to_box = 5;
                    }
                } else {
                    if (0 <= j && j < 3) {
                        convert_to_box = 6;
                    } else if (3 <= j && j < 6) {
                        convert_to_box = 7;
                    } else {
                        convert_to_box = 8;
                    }
                }
                if (hash_row[i][digit - 1] 
                    || hash_col[j][digit - 1]
                    || hash_box[convert_to_box][digit - 1]) {
                    return false;
                }
                hash_row[i][digit - 1]++;
                hash_col[j][digit - 1]++;
                hash_box[convert_to_box][digit - 1]++;
            }
        }
        return true;
    }
};

// Prettier version but harder to understand
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // hash[x][y] : keep track of x row and if number y has been put or not
        // x denotes which row/col/sub_boxes is it 
        // y denotes the number from 1 to 9 in sudoku
        vector<vector<int>> hash_row(board.size(), vector<int> (board[0].size()));
        vector<vector<int>> hash_col(board.size(), vector<int> (board[0].size()));
        vector<vector<int>> hash_box(board.size(), vector<int> (board[0].size()));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') continue;
                int digit = board[i][j] - '0';
                int convert_to_box = 0;
                for (int k = 0; k < 3; ++k) {
                    if ((k * 3) <= i && i < ((k + 1) * 3)) {
                        if (0 <= j && j < 3) {
                            convert_to_box = k * 3;
                        } else if (3 <= j && j < 6) {
                            convert_to_box = (k * 3) + 1;
                        } else {
                            convert_to_box = (k * 3) + 2;
                        }
                    } 
                }
                if (hash_row[i][digit - 1] 
                    || hash_col[j][digit - 1]
                    || hash_box[convert_to_box][digit - 1]) {
                    return false;
                }
                hash_row[i][digit - 1]++;
                hash_col[j][digit - 1]++;
                hash_box[convert_to_box][digit - 1]++;
            }
        }
        return true;
    }
};