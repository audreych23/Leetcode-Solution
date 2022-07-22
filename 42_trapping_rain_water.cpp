class Solution {
public:
  int trap(vector<int>& height) {
    int l {0};
    int r { int(height.size() - 1) };
    // prev_height is to keep track how much unit area we can gain
    int prev_max_height {0};
    int curr_max_height {-1};
    auto area {0};
    while (!area && l < r) {
      auto curr_height { min(height[l], height[r]) }; // the curr_height is the height that traps the water
      area += (curr_height * (r - l - 1)); // assign area the first time until area is not 0
      if (curr_max_height < curr_height) {
        curr_max_height = curr_height;
      }
      if (height[l] < height[r]) {
        l++;
        if (l == r) break;
        area -= min(curr_max_height, height[l]);
      } else {
        r--;
        if (l == r) break;
        area -= min(curr_max_height, height[r]);
      }
    }
    while(l < r) {
      auto curr_height { min(height[l], height[r]) }; // the curr_height is the height that traps the water
      // curr_max_height is the maximum height right now that can trap the water
      // say even if h[l] is 3 and h[r] is 2 curr_max_height will be 2 (assuming curr_max_height less than 2 previously)
      if (curr_height > curr_max_height) {
        prev_max_height = curr_max_height;
        curr_max_height = curr_height;
        area += ((curr_max_height - prev_max_height) * (r - l - 1));
      }
      if (height[l] < height[r]) {
        l++;
        if (l == r) break;
        area -= min(curr_max_height, height[l]);
      } else {
        r--;
        if (l == r) break;
        area -= min(curr_max_height, height[r]);
      }
    }
    return area;
  }
};
