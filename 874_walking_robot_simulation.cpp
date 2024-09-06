class Solution {
public:
    // north:+0 +1, right: +1 +0, bottom: +0 -1 left -1 0
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // dir when you turn right
        vector<pair<int, int>> dir({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
        map<pair<int, int>, int> obs;
        for (const auto& ob: obstacles) {
            obs[make_pair(ob[0], ob[1])] = 1;
        } 
        int curr_pos_x = 0;
        int curr_pos_y = 0;
        int dir_idx = 0;
        int max = 0;
        for (auto& c: commands) {
            if (c == -1) {
                dir_idx++;
                if (dir_idx == dir.size()) {
                    dir_idx = 0;
                }
            } else if (c == -2) {
                dir_idx--;
                if (dir_idx == -1) {
                    dir_idx = dir.size() - 1;
                }
            } else {
                int dir_x = dir[dir_idx].first;
                int dir_y = dir[dir_idx].second;
                while (c--) {
                    // pre check before moving
                    if (obs.find(make_pair(curr_pos_x + 1 * dir_x, curr_pos_y + 1 * dir_y)) == obs.end()) {
                        
                        curr_pos_x += 1 * dir_x;
                        curr_pos_y += 1 * dir_y;
                        if (max < curr_pos_x * curr_pos_x + curr_pos_y * curr_pos_y) {
                            max = curr_pos_x * curr_pos_x + curr_pos_y * curr_pos_y;
                        }
                    }
                }  
            }
        }
        return max;
        
    }
};