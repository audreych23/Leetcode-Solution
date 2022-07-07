class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<char, int> char_idx;
    int cnt {}; int ptr {};
    int max {};
    for (int i {}; i < s.length(); ++i) {
      // use double pointer to reset dont just fill everything to -1
      if (char_idx.find(s[i]) != char_idx.end()) {
        if (max < cnt) {
          max = cnt;
        }
        int prev_idx = char_idx[s[i]];
        for (ptr; ptr < (prev_idx + 1); ++ptr) {
          char_idx.erase(s[ptr]);
          cnt--;
        }
      }
      char_idx[s[i]] = i;
      cnt++;
    }
    // don't have to check until ptr reaches end of string because it will never be the longest substring without repeating characters
    if (max < cnt) {
      max = cnt;
    }
    return max;
  }
};
