/**
 * Brute force method
 * Time Complexity: O(mn)
 * Space Complexity : O(1)
 */
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    if (needle.length() > haystack.size()) return -1;
    for (int i {}; i < haystack.size() - needle.size() + 1; ++i) {
      for (int j {i}; j < i + needle.size(); ++j) {
        if (haystack[j] != needle[j - i]) {
          break;
        }
        if (j == i + needle.size() - 1 && haystack[j] == needle[j - i]) {
          return i;
        }
      }
    }
    return -1;
  }
};
