class Solution {
public:
  string convert(string s, int numRows) {
    // divide a substring to be able to calculate what's the offset and the zigzag part
    // e.g
    // ABCDEFGHIJKLM numRows = 4
    // ABCD||EF||GHIJ||KL||M
    // ABCD part is numRows, the EF part is always numRows - 2
    // ABCD EF and GHIJ KL is just a repetition
    string buf {""};
    int curr_row {1};
    int curr_idx {};
    if (numRows == 1) return s;
    for (int curr_row {1}; curr_row <= numRows; ++curr_row) {
      curr_idx = curr_row - 1;
      while(curr_idx < s.length()) {
        buf = buf + s[curr_idx];
        if (curr_row != 1 && curr_row != numRows) {
          // calculate the zig zag part
          int temp_idx = curr_idx + (numRows - curr_row) + (numRows - 2) - (curr_row - 2); // wrote curr_row - 1 but got an off by one error
          if (temp_idx < s.length()) buf = buf + s[temp_idx];
        }
        // calculate the next offset where to start
        curr_idx = curr_idx + (numRows) + (numRows - 2);
      }
    }
    return buf;
  }
};
