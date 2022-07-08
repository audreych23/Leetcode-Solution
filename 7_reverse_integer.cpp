class Solution {
public:
  int reverse(int x) {
    string MAX_INT { to_string(numeric_limits<int>::max()) };
    string MIN_INT { to_string(numeric_limits<int>::min()) };
    string str_num {};
    bool neg {};
    if (to_string(x) == MIN_INT) return 0; // the only case when x = x * -1 will overflow and when we flip it it's also gonna be more than int
    if (x < 0) { neg = true; x *= -1; } // change to positive
    while (x) {
      int digit = x % 10;
      x /= 10;
      str_num += to_string(digit);
    }

    string lead_zero {};
    if (!neg) {
      while (lead_zero.length() < MAX_INT.length() - str_num.length()) {
        lead_zero += '0';
      }
      str_num = lead_zero + str_num;
    } else {
      while (lead_zero.length() < MIN_INT.length() - str_num.length() - 1) {
        lead_zero += '0';
      }
      str_num = '-' + lead_zero + str_num;
    }

    if ((!neg && str_num > MAX_INT) || (neg && str_num > MIN_INT)){
      return 0;
    } else {
      return stoi(str_num);
    }
  }
};
