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
