/**
 * Time Complexity : O(n^3)
 * Space Complexity : O(n^2) or O(n) (because each vector only has 4 elements) ?
 */
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if (nums.size() < 4) return ans;
    sort(nums.begin(), nums.end());
    for (int i {}; i < nums.size() - 3; ++i) {
      if (i != 0 && nums[i] == nums[i - 1]) continue; // duplicate nums[i]
      for (int j {i + 1}; j < nums.size() - 2; ++j) {
        if (j != i + 1 && nums[j] == nums[j - 1]) continue; // duplicate nums[j]
        long long new_target { (long long)target - (long long)nums[i] - (long long)nums[j] }; // careful of overflow
        int l { j + 1 };
        int r { int(nums.size() - 1) };
        while (l < r) {
          long long sum { (long long) (nums[l] + nums[r]) }; // careful of overflow
          if (sum < new_target) {
            l++;
          } else if (sum > new_target) {
            r--;
          } else {
            vector<int> temp { nums[i], nums[j], nums[l], nums[r] };
            ans.push_back(temp);
            while(l < r && nums[l] == temp[2]) l++;
            while(l < r && nums[r] == temp[3]) r--;
          }
        }
      }
    }
    return ans;
  }
};
/**
 * Explanation: really similar to 3sum, add a new second loop
 * and just take care of overflow and if the size of input is less than 4
 */
