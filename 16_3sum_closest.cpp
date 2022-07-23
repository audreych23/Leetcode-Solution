/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    auto min_dis {10001};
    bool less {}, early {};
    sort(nums.begin(), nums.end());
    for (int i {}; i < int(nums.size()) - 2; ++i) {
      int new_target { target - nums[i] };
      int l { i + 1 };
      int r { int(nums.size()) - 1 };
      while(l < r) {
        int sum { nums[l] + nums[r] };
        // the 3 number sum distances compared to target
        if (min_dis > abs((sum + nums[i]) - target)) {
          min_dis = abs((sum + nums[i]) - target);
          // check if the min_dis is less or more than
          // do we move forward or backward in the number line
          if (sum + nums[i] < target) less = 1;
          else less = 0;
        }
        // this is the same as nums[l] + nums[r] + nums[i] < target
        if (sum < new_target) {
          l++;
        } else if (sum > new_target) {
          r--;
        } else {
          early = 1;
          break; // because min_dis will be 0
        }
      }
      if (early) break;
    }
    if (less) {
      return target - min_dis;
    }
    return target + min_dis;
  }
};
/**
 * Explanation : similar idea to number 15, to find the closest we will calculate the 2 distance of number
 * and the we get the minimum distance, then we need a boolean less to take care if the sum is less or larger than the
 * target (because we only store the distance (absolute between the sum and the target))
 * Notes : think of it like a number line
 */
