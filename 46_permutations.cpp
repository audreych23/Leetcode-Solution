/**
 * Time Complexity: O(n!)
 * Space Complexity: O(n)
 */
class Solution {
  void _permute(int start, const vector<int> &nums, vector<int> &ans, vector<vector<int>> &result, vector<int> &visited) {
    if (ans.size() == nums.size()) {
      result.push_back(ans);
      return;
    }
    for (int i {}; i < nums.size(); ++i) {
      if (!visited[i]) {
        visited[i] = 1;
        ans.push_back(nums[i]);
        _permute(i + 1, nums, ans, result);
        ans.pop_back();
        visited[i] = 0;
      }
    }
    return;
  }
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> ans;
    vector<int> visited(nums.size());
    _permute(0, nums, ans, result, visited);
    return result;
  }
};

/**
 * Another really clean solution from leetcode I found
 * Time Complexity: O(n!)
 * Space Complexity: O(1) // doesn't care about space to return
 **/
class Solution {
  void _permute(int start, vector<int> &nums, vector<vector<int>> &result) {
    if (start >= nums.size()) {
      result.push_back(nums);
      return;
    }
    // invariant : nums[0...begin - 1] have been permuted/ fixed
    // permute nums[begin...end]
    for (int i {start}; i < nums.size(); ++i) {
      swap(nums[i], nums[start]);
      _permute(start + 1, nums, result);
      // reset swap
      swap(nums[i], nums[start]);
    }
  }
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    _permute(0, nums, result);
    return result;
  }
};
