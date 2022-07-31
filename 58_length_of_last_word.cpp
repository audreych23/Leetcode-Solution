/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
  int lengthOfLastWord(string s) {
    int n { int(s.size() - 1) };
    bool first { true };
    for (int i { n }; i >= 0; --i) {
      if (!first && s[i] == ' ') return n - i;
      else if (first && s[n] == ' ') n--;
      else if (first && s[n] != ' ') first = false;
    }
    return n + 1;
  }
};
