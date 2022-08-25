/**
 * Time Complexity: O(max(n, m)) // size of ransomNote and size of magazine
 * Space Complexity: O(26)
 */
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int arr[26] = {};
    for (const auto& m : magazine) {
      arr[m - 'a']++;
    }

    bool can_construct = true;
    for (const auto& r : ransomNote) {
      if (arr[r - 'a']) {
        arr[r - 'a']--;
      } else {
        can_construct = false;
        break;
      }
    }
    return can_construct;
  }
};
