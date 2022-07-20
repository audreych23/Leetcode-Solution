/**
 * Time Complexity: O(n)
 * Space Complexity : O(1)
 */
class Solution {
public:
  int maxArea(vector<int>& height) {
    auto max {-1};
    auto left {0};
    auto right {height.size() - 1};
    while (left < right) {
      auto area {0};
      if (height[left] < height[right]) {
        area = height[left] * (right - left);
        left++;
      } else {
        area = height[right] * (right - left);
        right--;
      }
      if (max < area) {
        max = area;
      }
    }
    return max;
  }
};

/**
 * Explanation idea : normally brute force way is O(n^2) to find the max of n^2 combinations
 * of the (x2 - x1) and min(y1, y2)
 * But we can actually cut out some of the possible combinations with 2 pointers
 * from the if statement we can see that the water is bounded by the minimum y (y1 or y2), say y1.
 * Hence, the next element after y1, if it is larger it is possible to be maximum
 * it is only possible since it is bounded by the minimum y and since we go from larger x to smaller x
 * other cases that needs to be thought of is height[left] == height[right], but this doesn't matter
 * whether you move left or right pointer first (can be proven / shown)
 */
