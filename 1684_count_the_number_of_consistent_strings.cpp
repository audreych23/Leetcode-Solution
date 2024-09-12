class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s;
        for (int i = 0; i < allowed.size(); ++i) {
            s.insert(allowed[i]);
        }
        int count = 0;
        for (auto word : words) {
            set<char> sc;
            for (auto letter : word) {
                sc.insert(letter);
            }
            if (includes(s.begin(), s.end(), sc.begin(), sc.end())) count++;
        }
        return count;
    }
};