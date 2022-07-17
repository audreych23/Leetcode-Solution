/**
 * time complexity : O(n^2 log n) i think it's more ?
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    auto it_i {nums.begin()};
    vector<vector<int>> ans;
    for (it_i; it_i != prev(prev(nums.end())); ++it_i) {
      if (it_i != nums.begin() && *it_i == *prev(it_i)) continue;
      for (auto it_j {next(it_i)}; it_j != prev(nums.end()); ++it_j) {
        if (it_j != next(it_i) && *it_j == *prev(it_j)) continue;
        auto num = *it_i + *it_j;
        if (binary_search(next(it_j), nums.end(), -num)) {
          ans.push_back({ *it_i, *it_j, -num });
        }
      }
    }
    return ans;
  }
};

/**
 * Other solution : double pointer, faster
 * time complexity : O(n^2)
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i {}; i < int(nums.size()) - 2; ++i) {
      // take care of duplicates
      if (i > 0 && nums[i] == nums[i - 1]) continue; // 1st ele
      if (nums[i] > 0) break; // no triple if the first number is already > 0 because it is sorted
      int sum = -nums[i];
      int front {i + 1};
      int back {int(nums.size()) - 1};
      while (front < back) {
        if (sum > (nums[front] + nums[back])) {
          ++front;
        } else if (sum < (nums[front] + nums[back])) {
          --back;
        } else {
          vector<int> curr_ans {nums[i], nums[front], nums[back]};
          ans.push_back(curr_ans);

          // take care of duplicate
          while (front < back && nums[front] == curr_ans[1]) front++; // 2nd ele
          while (front < back && nums[back] == curr_ans[2]) back--;  // 3rd ele
        }
      }
    }
    return ans;
  }
};
