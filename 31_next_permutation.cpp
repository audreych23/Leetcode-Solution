/**
 * Find points that are not sorted in desc order, the next subarray after has to be sorted/swapped
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
private:
    void swap(int& a, int& b) {
        int temp = a; a = b; b = temp;
    }
public:
    void nextPermutation(vector<int>& nums) {
        // this is very important as it chooses which element should we swap
        // invariant : everything else before start_next_perm can be ignored because
        // of the characteristic of next permutation as we only need to get the next 
        // larger lexicographical number
        // so if it's not descendingly sorted we at some point then we will start from there
        int start_next_perm = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            // special case
            if (i == nums.size() - 2 && nums[i] < nums[i + 1]) {
                swap(nums[i + 1], nums[i]);
                return;
            } else if (i != nums.size() - 2 && nums[i] < nums[i + 1]) {
                start_next_perm = i;
                break;
            } else {
                // it's the last permutation
                if (i == 0) {
                    sort(nums.begin(), nums.end());
                    return;
                }
            }
        }
        // this case is basically for what if 
        // 1 *3* 5 4 2 (everything is correctly sorted after 3, subarray after 3 also has size > 2) [5 4 2]
        // next perm should be 1 *4* 2 3 5
        // so the subarray after 4 should be ascendingly sorted 
        // below is the idea
        for (int i = nums.size() - 1; i > start_next_perm; --i) {
            if (nums[start_next_perm] < nums[i]) {
                // first find the first largest nums that are larger than the number we want to permute
                // swap with the number we want to start permuting
                swap(nums[start_next_perm], nums[i]);
                // 0 1 2 3 4 5
                // if start_next_perm == 2, 6 - 1 - 2 = 3, 3/2 = 1
                int num_swap_elem = (nums.size() - 1 - start_next_perm) / 2;
                int k = 1;
                while (num_swap_elem) {
                    // we can do this because after we have indicated the number that is about to
                    // be swapped e.g 1 *3* 5 4 2
                    // and has been swapped before this loop 
                    // 1 *4* 5 3 2 (then swap 5 and 2)
                    // swapping the first largest number will still make the subarray [ 5 3 2 ] still sorted in desc order
                    // just have to swap 2 and 5, by induction it is true for any subarray
                    // because we will only choose start_next_perm when they are in ascending order 
                    swap(nums[start_next_perm + k], nums[nums.size() - k]);
                    k++;
                    num_swap_elem--;
                }
                break;
            }
        }
        return;
    }
};