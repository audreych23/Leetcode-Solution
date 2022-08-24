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

/**
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * Description: Math way, only works if it's a prime, power_of_two, three, five etc
 */
constexpr int _maxPowerOfThree() {
  int n = 3;
  while (n < numeric_limits<int>::max() / 3) {
    n *= 3;
  }
  return n;
}
class Solution {
public:
  bool isPowerOfThree(int n) {
    constexpr int maxPowerOfThree = _maxPowerOfThree();
    return n > 0 && maxPowerOfThree % n == 0;
  }
};
/**
 * Idea: find the highest "power of three" number before the integer limit, because that number will have a
 * factor of every other power of three numbers smaller than it. it only works with prime numbers.
 * (proof redacted (haven't tried proofing it xd)) has something to do with FLT (Fermat's Little Theorem ?)
 * e.g 81 is 3^4 = 3^3 * 3 = 3^2 * 3^2 (consist of only one prime factor)
 * composite number would consist of other factor hence why it won't work
 * e.g 216 = 6^3 = 2^3 * 3^3 (mod 2 == 0 and mod 3 == 0)
 */
/**
 * Warning: in leetcode, idk why but it's slower than O(log n) method, (46 ms)
 * constexpr only works when I put it outisde of class (doesn't really know why but link below might help)
 * Link: https://stackoverflow.com/questions/30089131/c-constexpr-auto-member-function-clang-issue
 */

/**
 * Same solution as above just tweeked
 */
class Solution {
public:
  bool isPowerOfThree(int n) {
    const int maxPowerOfThree = 1162261467; // 3^19
    return n > 0 && maxPowerOfThree % n == 0;
  }
};
