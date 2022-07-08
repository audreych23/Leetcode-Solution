class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int max_len {};
    string base_len {};
    for (auto s : strs) {
      if (s.length() > max_len) {
        max_len = s.length();
        base_len = s;
      }
    }
    bool is_longest { true };
    for (int i { max_len }; i >= 0; --i) {
      is_longest = true;
      for (auto s : strs) {
        if (s.substr(0, i) != base_len.substr(0, i)) {
          is_longest = false;
          break;
        }
      }
      if (is_longest) {
        return base_len.substr(0, i);
      }
    }
    return "";
  }
};
