class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ptr1 = 0;
        int ptr2 = 0;
        int sum = 0;
        int min = numeric_limits<int>::max();
        while (ptr2 < nums.size()){
            if (sum < target) {
                sum += nums[ptr2];
                ptr2++;
            } else if (sum >= target) {
                int l = ptr2 - ptr1;
                if (l < min) {
                    min = l;
                }
                sum -= nums[ptr1];
                ptr1++;
            }   
        }
        // ptr1 might still be in the middle whilst ptr2 ended already
        while (ptr1 < nums.size()) {
            if (sum >= target) {
                int l = ptr2 - ptr1;
                if (l < min) {
                    min = l;
                }
            }   
            sum -= nums[ptr1];
            ptr1++;
        }
        // final check 
        if (sum >= target) {
            int l = ptr2 - ptr1;
            if (l < min) {
                min = l;
            }
            // case if final number is target
        }
        if (min == numeric_limits<int>::max()) return 0;
        return min;
    }
};