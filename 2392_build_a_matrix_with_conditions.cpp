class Solution {
    void DFSCheckCycle(vector<vector<int>>& graph, int current, int& no_sol,
                               vector<int>& visited, vector<int>& path) // to check if there is a backedge
    {
        visited[current] = 1; path[current] = 1;
        for (const auto& child : graph[current]) {
            if (!visited[child]) {
                DFSCheckCycle(graph, child, no_sol, visited, path);
            } else {
                if (path[child] == 1) {
                    // means there is a cycle
                    no_sol = true;
                }
            }
        }
        path[current] = 0;
        return;
    }
    
    void TopologicalSort(vector<vector<int>>& graph,
                        vector<int>& in_deg, vector<int>& indices) 
    {
        queue<int> q;
        for (int i = 0; i < in_deg.size(); ++i) {
            if (in_deg[i] == 0) q.push(i);
        }
        int k = 0;
        while (!q.empty()) {
            int current = q.front(); q.pop();
            indices[current] = k++;
            for (auto const& child : graph[current]) {
                if (--in_deg[child] == 0) q.push(child);
            }
        }
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // contain element from 0 to k - 1 
        vector<vector<int>> graph(k);
        vector<int> in_deg(k);
        
        // the ith index indicate that the element i should be put on row of the index of row[i]
        // aka i = 2 means element 2 should be put on row[2] and col[2] (e.g 3, 1)
        vector<int> row(k);
        vector<int> col(k);
        // create a DAG
        for (const auto& row : rowConditions) {
            auto above = row[0];
            auto below = row[1];
            // above is parent of below
            graph[above - 1].push_back(below - 1);
            in_deg[below - 1]++;
        }
        
        vector<int> visited(k);
        vector<int> path(k);
        
        int no_sol = 0;
        
        for (int i = 0; i < k; ++i) {
            if (!visited[i]) DFSCheckCycle(graph, i, no_sol, visited, path);
            if (no_sol) { return vector<vector<int>> (); }
        }
        
        TopologicalSort(graph, in_deg, row);
        
        graph = vector<vector<int>> (k);
        in_deg = vector<int> (k);
        
        for (const auto& col : colConditions) {
            auto left = col[0];
            auto right = col[1];
            graph[left - 1].push_back(right - 1);
            in_deg[right - 1]++;
        }
        
        visited = vector<int> (k);
        path = vector<int> (k);
        no_sol = 0;
        
        for (int i = 0; i < k; ++i) {

            if (!visited[i]) DFSCheckCycle(graph, i, no_sol, visited, path);
            if (no_sol){ return vector<vector<int>> (); }
        }
        
        TopologicalSort(graph, in_deg, col);
        
        vector<vector<int>> solution(k, vector<int> (k));
        for (int i = 0; i < k; ++i) {
            solution[row[i]][col[i]] = (i + 1);
        }
        return solution;
        
    }
};

// better solution
class Solution {
    bool TopologicalSort(vector<vector<int>>& graph,
                        vector<int>& in_deg, vector<int>& indices) 
    {
        queue<int> q;
        for (int i = 0; i < in_deg.size(); ++i) {
            if (in_deg[i] == 0) q.push(i);
        }
        int k = 0;
        while (!q.empty()) {
            int current = q.front(); q.pop();
            indices[current] = k++;
            for (auto const& child : graph[current]) {
                if (--in_deg[child] == 0) q.push(child);
            }
        }
        return k != graph.size();
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // contain element from 0 to k - 1 
        vector<vector<int>> graph(k);
        vector<int> in_deg(k);
        
        // the ith index indicate that the element i should be put on row of the index of row[i]
        // aka i = 2 means element 2 should be put on row[2] and col[2] (e.g 3, 1)
        vector<int> row(k);
        vector<int> col(k);
        // create a DAG
        for (const auto& row : rowConditions) {
            auto above = row[0];
            auto below = row[1];
            // above is parent of below
            graph[above - 1].push_back(below - 1);
            in_deg[below - 1]++;
        }
        
        vector<int> visited(k);
        vector<int> path(k);
        
        bool no_sol = TopologicalSort(graph, in_deg, row);
        if (no_sol) return vector<vector<int>> ();
        
        graph = vector<vector<int>> (k);
        in_deg = vector<int> (k);
        
        for (const auto& col : colConditions) {
            auto left = col[0];
            auto right = col[1];
            graph[left - 1].push_back(right - 1);
            in_deg[right - 1]++;
        }
        
        visited = vector<int> (k);
        path = vector<int> (k);
        
        no_sol = TopologicalSort(graph, in_deg, col);
        if (no_sol) return vector<vector<int>> ();
        
        vector<vector<int>> solution(k, vector<int> (k));
        for (int i = 0; i < k; ++i) {
            solution[row[i]][col[i]] = (i + 1);
        }
        return solution;
    }
};