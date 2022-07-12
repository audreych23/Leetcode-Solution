class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int ptr {};
    int cnt {};
    for (int i {}; i < int(nums.size()) - 1; ++i) {
      if (nums[i] != nums[i + 1]) {
        if (ptr != i) {
          nums[ptr + 1] = nums[i + 1];
        }
        ptr++;
        cnt++;
      }
    }
    return cnt + 1;
  }
};
