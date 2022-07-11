/**
 * the op_depth is to keep track how many open bracket you have left
 * the cl_depth is to keep track how many close bracket that you have to use
 * the if case is really important because it takes care of if you should put a '(' or not ')'
 */
class Solution {
private:
  void _generateParenthesis(int op_depth, int cl_depth, string str, vector<string> &v) {
    if (!op_depth && !cl_depth) {
      v.push_back(str);
      return;
    }
    if (op_depth) {
      _generateParenthesis(op_depth - 1, cl_depth + 1, str + '(', v);
    }

    if (cl_depth) {
      _generateParenthesis(op_depth, cl_depth - 1, str + ')', v);
    }
  }
public:
  vector<string> generateParenthesis(int n) {
    vector<string> v;
    string str {};
    _generateParenthesis(n, 0, str, v);
    return v;
  }
};
