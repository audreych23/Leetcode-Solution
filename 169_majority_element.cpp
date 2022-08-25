/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> table;
    for (const auto& num: nums) {
      table[num]++;
    }
    auto max {0};
    auto ans {0};
    for (const auto& element: table) {
      if (max < element.second) {
        ans = element.first;
        max = element.second;
      }
    }
    return ans;
  }
};

/**
 * Boyer-Moore majority vote algorithm
 * https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
  // only one pass is needed because from the q it is guaranteed to have majority element
  // two pass is needed if not guaranteed, just check if the amount of curr_major has more than floor(n/2)
  int majorityElement(vector<int>& nums) {
    int cnt {0}, curr_major {0};
    for (const auto& num : nums) {
      if (!cnt) {
        curr_major = num;
        cnt = 1;
      } else if (curr_major == num) {
        cnt++;
      } else {
        cnt--;
      }
    }
    return curr_major;
  }
};

/**
 * idea: you canncel them out together for every count, we can appoint a new majority when a count reach 0
 * e.g 2 2 1 1 1 1
 * the first 2 and the first 1 cancels out and then we can see that next majority
 * will be starting from the 5th element, then we set 1 as the curr_major. next element wont change majority
 * so current major is one.
 * invariant is basically the non-majority number will get cancelled out with some of the majority number
 */
