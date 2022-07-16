class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> nums;
    int i {}, j {}, k {};

    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        nums.push_back(nums1[i]);
        i++;
      } else {
        nums.push_back(nums2[j]);
        j++;
      }
      k++;
    }

    while (i < m) {
      nums.push_back(nums1[i]);
      i++; k++;
    }

    while (j < n) {
      nums.push_back(nums2[j]);
      j++; k++;
    }
    nums1 = nums;
    return;
  }
};
