class Solution {
   public:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool is_boundary(int i, int j) {
        return 0;  // todo
    }

    int bfs(int i, int j, vector<vector<int>>& grid) {
        int res = 0;
        queue<vector<int>> q;
        int n = grid.size();
        int m = grid[0].size();

        // overwrite grid to negative values to emulate visited set

        q.push({i, j});
        grid[i][j] = -1;


        while (!q.empty()) {
            // access, mark as visited
            vector<int> curr = q.front();
            
            q.pop();

            // check neighbors and processes accordingly
            for (auto d : dirs) {
                int newi = curr[0] + d.first;
                int newj = curr[1] + d.second;

                if (newi < 0 || newi >= n || newj < 0 || newj >= m) {
                    // grid boundary
                    res++;
                } else {
                    // within bounds
                    if (grid[newi][newj] < 0) {
                        // do nothing, its visited
                    } else if (grid[newi][newj] == 0) {
                        res++;
                    } else {
                        grid[newi][newj] = -1;
                        q.push({newi, newj});
                    }
                }
            }
        }

        return res;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int starti = -1;
        int startj = -1;

        int n = grid.size();
        int m = grid[0].size();

        // 2d traversal until we find the island

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // start bfs
                    res = bfs(i, j, grid);
                }
            }
        }

        return res;

        // then bfs and accumulate is_boundary counter while we explore the entire island

        // return accumulation
    }
};