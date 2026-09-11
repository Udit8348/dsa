class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // adapt interative bfs to djikstra: priority queue greedily chooses least diff to explore and visited becomes a cost map

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        using ADT = vector<int>;
        priority_queue<ADT, vector<ADT>, greater<ADT>> pq;  // (cost, row, col)
        vector<vector<int>> costs (n, vector<int>(m, INT_MAX));                          // costs[r][c]

        costs[0][0] = 0;
        pq.push({0,0,0});

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int row = curr[1];
            int col = curr[2];

            // check if we reached target
            if (row == n - 1 && col == m - 1) {
                return cost;
            }

            if (cost > costs[row][col]) {
                // this path is more expensive than a previous method to get to this pos
                continue;
            }

            for (vector<int> d : dirs) {
                int next_row = row + d[0];
                int next_col = col + d[1];

                if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
                    // determine if taking this step minimizes the global min
                    
                    int step_diff = abs(heights[row][col] - heights[next_row][next_col]);
                    int next_cost = max(cost, step_diff);
                    
                    if (costs[next_row][next_col] > next_cost) {
                        costs[next_row][next_col] = next_cost;
                        pq.push({next_cost, next_row, next_col});
                    }
                }
            }
        }
        return 0;

        

    }
};