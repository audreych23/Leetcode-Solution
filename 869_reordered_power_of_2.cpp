/**
 * Time Complexity: O(log n)
 * Space Complexity: O(log^2 n) // kinda hard to measure I guess O(1) ?
 */
class Solution {
public:
  bool reorderedPowerOf2(int n) {
    auto MAX_INT {std::numeric_limits<int>::max()};
    vector<string> pow_2;
    // because in store 4 bytes = 32 bits which is 2^31 highest power of 2 (0th bit is sign bit)
    // highest number that can be represented is 2^32 - 1
    for(int i {}; i < 31; ++i) {
      pow_2.push_back(to_string(1 << i));
    }
    // sort all digits in each number in the vector e.g 1024 = 0124
    for (int i {}; i < 31; ++i) {
      sort(pow_2[i].begin(), pow_2[i].end());
    }
    // sort n and compare with the vector;
    auto string_to_compare { to_string(n) };
    sort(string_to_compare.begin(), string_to_compare.end());
    for (int i {}; i < 31; ++i) {
      if (string_to_compare == pow_2[i]) {
        return true;
      }
    }
    return false;
  }
};
/**
 * Idea: generate all power of 2 number until the maximum integer limit (due to question constraint)
 * sort all of them and then compare one by one with the also sorted input number
 */
