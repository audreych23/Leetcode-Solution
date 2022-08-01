/**
 * Time Complexity: O(n)
 * Space Complexity: O(26)
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

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
  char repeatedCharacter(string s) {
    // char 'a' -> 0th bit is flipped, 'b' -> 1st bit, 'c' -> 2nd, etc
    // if 'a' and 'd' is met it's gonna be 1001 in bit -> val = 9
    int val {};
    for (int i {}; i < int(s.size()); ++i) {
      // check if the bit is flipped to 1 by shifting right by s[i] bit where a -> 0, b -> 1
      if ((val >> (s[i] - 'a')) & 1) return s[i];
      // flip the bit in the corresponding position depending on s[i]
      val = val | (1 << (s[i] - 'a'));
    }
    return 'a'; // will not happen
  }
};
