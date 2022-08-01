/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> ans(digits.size());
    int k {int(digits.size()) - 1};
    int carry {};
    for (int i {int(digits.size()) - 1}; i >= 0; --i) {
      if (i == int(digits.size()) - 1) {
        digits[i] += 1;
      }
      digits[i] += carry;
      if (digits[i] >= 10) {
        carry = 1;
        digits[i] %= 10;
      } else {
        carry = 0;
      }
      ans[k] = digits[i];
      k--;
    }
    if (carry) {
      vector<int> new_ans(ans.size() + 1);
      new_ans[0] = 1;
      for (int i {}; i < ans.size(); ++i) {
        new_ans[i + 1] = ans[i];
      }
      return new_ans;
    }
    return ans;
  }
};
