/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
  char repeatedCharacter(string s) {
    vector<int> alph(26);
    for (int i {}; i < int(s.size()); ++i) {
      if (alph[s[i] - 'a']) return s[i];
      alph[s[i] - 'a']++;
    }
    return 'a'; // will not happen
  }
};
