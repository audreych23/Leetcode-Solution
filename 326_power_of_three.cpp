/**
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n != 1) {
      if (!(n % 3)) {
        n/=3;
      } else {
        return false;
      }
    }
    return true;
  }
};
