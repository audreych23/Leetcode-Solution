class Solution {
private:
  void _combinationSum(
    int res, vector<int> &candidates,
    int target, vector<vector<int>>& possible_answer,
    vector<int>& answer, int prev_candidate
  ) {
    if (res > target) return;
    if (res == target) {
      possible_answer.push_back(answer);
      return;
    }
    for (int i {}; i < int(candidates.size()); ++i) {
      // cut the branch of dfs if example [2, 3, ] and next element to put is 2 because prev 3 is larger than 2
      // (since it is sorted) [2, 2, 3] will be made already at some point been made already which means [2, 3, 2] is a duplicate
      if (candidates[i] < prev_candidate) continue;
      answer.push_back(candidates[i]);
      _combinationSum(res + candidates[i], candidates, target, possible_answer, answer, candidates[i]);
      answer.pop_back();
    }
    return;
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> possible_answer; // to handle duplicates
    vector<int> answer;
    // sort the candidates to make it faster
    // we can cut the branch of to handle duplicates easier than using set, and using set is much slower
    sort(candidates.begin(), candidates.end());
    _combinationSum(0, candidates, target, possible_answer, answer, -1);
    return possible_answer;
  }
};
/**
 * Notes :
 * candidates doesn't have to be sorted but it makes more sense if you sort it (see above comment)
 * also faster, sort candidate = 8 ms, not sorting it makes it 16 ms
 * used set to handle duplicate causes TLE
 */
