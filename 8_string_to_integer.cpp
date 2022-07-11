class Solution {
public:
  int myAtoi(string s) {
    bool is_lead { true };
    bool is_first_sign { false };
    bool is_lead_zero { true };
    stack<char> st;
    string str_ans {};
    for (int i {}; i <= int(s.length()); ++i) {
      if (s[i] == ' ' && is_lead) {
        continue;
      } else if (s[i] == '-' && !is_first_sign){
        is_lead = false;
        is_first_sign = true;
        // number is a negative number
        str_ans += '-';
      } else if ('0' <= s[i] && s[i] <= '9') {
        is_lead = false;
        is_first_sign = true;
        if (s[i] == '0' && is_lead_zero) { // take care of leading zero
          continue;
        } else if (s[i] != '0' && is_lead_zero) {
          is_lead_zero = false;
        }
        // number is not negative if we meet a '-' the it is invalid
        str_ans += s[i];
        st.push(s[i]);
      } else if (s[i] == '+' && !is_first_sign) {
        is_lead = false;
        is_first_sign = true;

      } else {
      // invalid
      // ignore everything behind it
        break;
      }
    }
    if (st.empty()) return 0;

    string MAX_INT { to_string(numeric_limits<int>::max()) };
    string MIN_INT { to_string(numeric_limits<int>::min()) };
    //return stoi(str_ans);
    //return str_ans.length();
    if (str_ans[0] != '-' && str_ans.length() > MAX_INT.length() || str_ans.length() == MAX_INT.length() && str_ans >= MAX_INT) {
      return numeric_limits<int>::max();
    } else if (str_ans[0] == '-' && str_ans.length() > MIN_INT.length() || str_ans.length() == MIN_INT.length() && str_ans >= MIN_INT) {
      return numeric_limits<int>::min();
    }

    long long int j { 1 };
    int ans {};

    while (!st.empty()) {

      char number { st.top() };
      ans += j * (number - '0');
      st.pop();
      j *= 10;
    }
    if (str_ans[0] == '-') {
      ans *= -1;
    }
    return ans;
  }
};
