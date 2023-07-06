/**
 * xor bitwise operation
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum ^= num;
        }
        return sum;
    }
};