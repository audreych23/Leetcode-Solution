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

/**
 * KMP algorithm
 * Time Complexity : O(m + n)
 * Space Complexity : O(m) // m is the needle size
 */
 class Solution {
 public:
   int strStr(string haystack, string needle) {
     if (needle.empty()) return 0;
     if (needle.length() > haystack.size()) return -1;
     vector<int> pi(int(needle.size()));
     // pre calculate longest proper prefix which is also a suffix
     for (int i {1}; i < needle.size(); ++i) {
      int j { pi[i - 1] };
      while (j > 0 && needle[i] != needle[j]) {
        j = pi[j - 1];
      }
      if (needle[i] == needle[j]) ++j;
      pi[i] = j;
     }

     int n { int(haystack.size()) };
     int m { int(needle.size()) };
     int i {}, j {};
     // find the index of a substring occurence
     while ((n - i) >= (m - j)) {
      if (haystack[i] == needle[j]) {
        ++i;
        ++j;
      }

      if (j == m) {
        return i - j;
      }
      if (i < n && haystack[i] != needle[j]) {
        if (j != 0) {
          j = pi[j - 1];
        } else {
          ++i;
        }
      }
     }
     return -1;
   }
 };
