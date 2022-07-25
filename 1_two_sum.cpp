/**
 * Time Complexity : O(n log n) ? because of the map insert (I think)
 * Space Complexity : O(n) ? multimap size ?
 */
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    multimap<int, int> mp;
    for (int i {}; i < nums.size(); ++i) {
      mp.insert( pair<int, int> {nums[i], i} );
    }
    sort(nums.begin(), nums.end());
    int l {0};
    int r { int(nums.size() - 1) };
    while (l < r) {
      if (nums[l] + nums[r] < target) {
        l++;
      } else if (nums[l] + nums[r] > target) {
        r--;
      } else {
        auto it { mp.find(nums[l]) };
        l = it->second;
        mp.erase(it); // erase in multimap so if nums[l] == nums[r] we can get another answer
        r = mp.find(nums[r])->second;
        return vector<int> {l, r};
      }
    }
    return vector<int> {};
  }
};
