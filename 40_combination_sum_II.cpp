class Solution {
private:
  void _combinationSum2(
    int res, vector<int> &candidates,
    int target, vector<vector<int>>& possible_ans,
    vector<int>& ans, int start
  ) {
    if (res > target) {
      return;
    }
    if (res == target) {
      possible_ans.push_back(ans);
      return;
    }
    // initializing i to start will take care of other branches duplicates such as [2, 5, 2] and [2, 2, 5] (will only take [2, 2, 5]) similar
    // to the previous way i did which is prev <= candidates[i] but cleaner and precise
    for (int i {start}; i < int(candidates.size()); ++i) {
      // when i > start it means it finishes returning and find the next element ++i
      // such element if it was similar to the previous one then u just skip because it's already called when i == start passing i + 1 to the next call
      if (i > start && candidates[i] == candidates[i - 1]) continue; // this handles the duplicates e.g [1, 2, 2] and [1, 2, 2]
      ans.push_back(candidates[i]);
      _combinationSum2(res + candidates[i], candidates, target, possible_ans, ans, i + 1); // start is i + 1 because we don't repeat them same index
      ans.pop_back();
    }
  }
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> possible_ans;
    vector<int> ans;
    sort(candidates.begin(), candidates.end());
    _combinationSum2(0, candidates, target, possible_ans, ans, 0);
    return possible_ans;
  }
};
/**
 * idea : some of the comments are written on the code
 * for clarification : first thing we need to handle is similar to combination I, which is 2, 2, 5 and 2, 5, 2
 * This can be done by initializing i to start because then it will just continue to the next element, 
 * no need to iterate back to the smallest element
 * the magic trick to handle [1*, 1_, 2, 3] so that it won't do [1*, 2, 3] and [1_, 2, 3]
 * is to sort it and we have to check if the next / prev element is the same
 * when we see 1 and 1 is the same it will just make the branch gone
 * i > start makes it also works on [1, 2, 2, 3] (not only the start of the call which is 1, 1, 2, 3)
 * I tried using it only first call failed at the above case
 * because start basically detects if it was the first time the function got called (loops hasn't started yet)
 * we need to worry about the loops because the next loops (not the next call) cause the duplicate above
 */
