class Solution {
public:
  string intToRoman(int num) {
    queue<int> q;
    while(num) {
      int dig { num % 10 };
      num /= 10;
      q.push(dig);
    }
    string str {};
    char arr1[4] = { 'I', 'X', 'C', 'M' };
    char arr5[3] = { 'V', 'L', 'D' };
    int i {}; // idx for the above array
    while (!q.empty()) {
      int dig { q.front() };
      if (dig == 1) {
        str = arr1[i] + str;
      } else if (dig == 2) {
        str = string(2, arr1[i]) + str;
      } else if (dig == 3) {
        str = string(3, arr1[i]) + str;
      } else if (dig == 4) {
        str = arr5[i] + str;
        str = arr1[i] + str;
      } else if (dig == 5) {
        str = arr5[i] + str;
      } else if (dig == 6) {
        str = arr1[i] + str;
        str = arr5[i] + str;
      } else if (dig == 7) {
        str = string(2, arr1[i]) + str;
        str = arr5[i] + str;
      } else if (dig == 8) {
        str = string(3, arr1[i]) + str;
        str = arr5[i] + str;
      } else if (dig == 9){
        str = arr1[i + 1] + str;
        str = arr1[i] + str;
      }
      i++;
      q.pop();
    }
    return str;
  }
};
