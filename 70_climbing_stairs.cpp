/**
 * DP bottom up approach
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 */
class Solution {
public:
  int climbStairs(int n) {
    vector<int> mem(n + 2); // careful of overflow here
    mem[1] = 1;
    mem[2] = 2;
    for (int i {3}; i <= n; ++i) {
      mem[i] = mem[i - 1] + mem[i - 2];
    }
    return mem[n];
  }
};

/**
 * DP top down approach
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution {
  int _climbStairs(int n, vector<int> &mem) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (mem[n] != 0) return mem[n]; // second time memorize
    mem[n] = _climbStairs(n - 1, mem) + _climbStairs(n - 2, mem);
    return mem[n]; // first time
  }
public:
  int climbStairs(int n) {
    vector<int> mem(n + 1); // careful of overflow here
    _climbStairs(n, mem);
    return mem[n];
  }
};
// add matrix way maybe?
