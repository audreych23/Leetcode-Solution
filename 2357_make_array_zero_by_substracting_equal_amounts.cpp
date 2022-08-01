/**
 * sort the element then brute force by adding the operation we did stored in ctr
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */
class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    sort(nums.begin(), begin.end());
    // greedy method, min operations is when you keep taking the minimum number at that point and sub it
    int ctr {}, ans {};
    for (int i {}; i < int(nums.size()); ++i) {
      // our operation at that point (ctr will accumulate to do all operation)
      nums[i] -= ctr;
      if (nums[i] <= 0) continue;
      else {
        ans++;
      }
      // accumulate the op we have done
      ctr += nums[i]
    }
    return ans;
  }
};

/**
 * count the unique element except for 0 in the array
 */
class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    unordered_map<int, int> mp;
    for(const auto& n: nums) {
      if (n) mp[n]++;
    }
    return mp.size();
  }
};
