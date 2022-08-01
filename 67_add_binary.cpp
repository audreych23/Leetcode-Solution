/**
 * Time Complexity: O(n)
 * Space Complexity: O(1) // using the same string to store the answer
 */
class Solution {
public:
  string addBinary(string a, string b) {
    // dealing with having not same length
    if (a.length() < b.length()) swap(a, b);
    while (b.length() < a.length()) {
      b = '0' + b;
    }
    bool carry {};
    for (int i {int(a.size()) - 1}; i >= 0; --i) {
      bool x = a[i] - '0'; bool y = b[i] - '0';
      bool s = x ^ y ^ carry;
      carry = (x & carry) | (x & y) | (y & carry); // k-map XD
      a[i] = s + '0';
    }
    if (carry) a = '1' + a;
    return a;
  }
};
// I wonder if there's a way to not fill it with leading zero if they don't hve the same length
