class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> result;
        int total_rolls = n + rolls.size();
        int rhs = total_rolls * mean;
        for (int i = 0; i < rolls.size(); ++i) {
            rhs -= rolls[i];
        }
        int res = rhs / n;
        int md = rhs % n;
        if (res <= 0 || res > 6 || (md > 0 && (res + 1) > 6) ) {
            return vector<int>();
        }
        while(md--) {
            result.push_back(res + 1);
        }
        while (result.size() < n) {
            result.push_back(res);
        }
        return result;
    }
};