/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        // denotes the result and also the bound that results in gap
        // the bound that might result in gaps for the consecutive values
        // is coins[i] <= max_curr_value with assumption that coins is sorted
        // e.g 1 2 5 results in gap and will return 4 as result (the 5 is ignored and 4 is returned)
        // 1 2 4 will return 7 because 
        int max_curr_value = 1;
        for (int i = 0; i < coins.size() && coins[i] <= max_curr_value; ++i) {
            max_curr_value += coins[i];
        }
        return max_curr_value;
    }
};
/**
 * idea : The idea is so big brain but the main idea that I got is
 * let's first think about the non duplicate number and is assumingly sorted
 * reason for this assumption that it's sorted is because in the question it's sorted already
 * and it looks easier to do it in sorted
 * if [1, 2] then result is 1 : 1, 2 : 2, 3 : 1 + 2
 * if [1, 2, 4] then result is 1 2 3 is the same 4 : 4, 5 : 4 + 1, 6 : 4 + 2, 7 : 4 + 1 + 2
 * if you notice if we have a 4, then we can reuse result from 1 2 3 to get 4 to 7 
 * (7 because 4 + 3 + 2 + 1 which is the maximum amount)
 * MAIN : if we could create x consecutive integers from 0 to i - 1, 
 * as long as x >= coins[i] the result will be x + coins[i]
 * and there will be no gap (consecutive being broken) unless x < coins[i]
 * this also works with duplicate because the same idea will work
 * test [1, 2, 2, 3]
 * [use coins[0] = 1 and coins[1] = 2] 1 : 1, 2 : 2, 3 : 1 + 2,  
 * [start using next coins[2] = 2] 4: 2 + 2, 5: 2 + 2 + 1, 
 * [start using next coins[3] = 3] 6 : 3 + 2 + 1, 7 : 3 + 2 + 2, 8 : 3 + 2 + 2 + 1
 * think about it as [[[[1, 2], 2], 3]] because the next coins[i] is used to get the next consecutive result
 * reference : https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/solutions/1118766/c-java-python-with-picture/
 */