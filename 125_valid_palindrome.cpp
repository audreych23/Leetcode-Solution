/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if (!s.size()) return 0;
        int start = 0;
        int end = s.size() - 1;
        while (start <= end && start <= s.size() - 1 && end >= 0) {
            while (start <= s.size() - 1 && !isalnum(s[start])) {
                start++;
            }
            while (end >= 0 && !isalnum(s[end])) {
                end--;
            }
            if (start >= s.size() - 1 || end <= 0) {
                break;
            }
            if (tolower(s[start]) == tolower(s[end])) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};