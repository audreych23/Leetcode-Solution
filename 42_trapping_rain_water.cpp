/**
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 */
class Solution {
public:
  int trap(vector<int>& height) {
    int l {0};
    int r { int(height.size() - 1) };
    // prev_height is to keep track how much unit area we can gain
    int prev_max_height {0};
    int curr_max_height {-1};
    auto area {0};

    while(l < r) {
      auto curr_height { min(height[l], height[r]) }; // the curr_height is the height that traps the water
      // curr_max_height is the maximum height right now that can trap the water
      // say even if h[l] is 3 and h[r] is 2 curr_max_height will be 2 (assuming curr_max_height less than 2 previously) (1.5)
      if (!area) { // case to initalize our initial area of water when especially the array starts or end with element 0 e.g [0*, 0*, 1, 0, 1, 0*]
        area += (curr_height * (r - l - 1));
        if (curr_max_height < curr_height) {
          curr_max_height = curr_height;
        }
      } else {
        if (curr_max_height < curr_height) {
          prev_max_height = curr_max_height;
          curr_max_height = curr_height;
          area += ((curr_max_height - prev_max_height) * (r - l - 1)); // (1)
        }
      }
      if (height[l] < height[r]) {
        l++;
        if (l == r) break;
        area -= min(curr_max_height, height[l]); // (2)
      } else {
        r--;
        if (l == r) break;
        area -= min(curr_max_height, height[r]);
      }
    }
    return area;
  }
};
/**
 * idea : using two pointers similar to question 11 (container with most water)
 * A very important idea is that rain water that is trapped will increase only when the next height
 * we find is higher than the previous max height other than that it's constant (1)
 * I define max_height as the maximum height of water that can be trapped which is like min of height[l] and height[r] (1.5)
 * and it's easy to subtract the amount of area water when the next height is smaller (2)
 * e.g [1, 0, 2, 0, 3, 1] at first the area trapped will be from [1, 1] index 0, 5 then using similar algo as number 11
 * we can increase the area of unit water around the trapped of [2, 3] index 2, 4
 */
