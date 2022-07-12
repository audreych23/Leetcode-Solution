class Solution {
private:
  void _letterCombinations(string digits, int k, string buf, vector<string> &result) {
    if (k == digits.length()) {
      result.push_back(buf);
      return;
    }
    for (int i {}; i < v[(digits[k] - '0') - 2].length(); ++i) {
      _letterCombinations(digits, k + 1, buf + v[(digits[k] - '0') - 2][i], result);
    }
  }
  vector<string> v {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) return result; // special case "" return empty vector
    _letterCombinations(digits, 0, "", result);
    return result;
  }
};
