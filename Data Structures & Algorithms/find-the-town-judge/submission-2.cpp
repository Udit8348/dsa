class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // bipartite check failed due to a lack of edge specificity

        // list all the incoming nodes to a sink at index i
        vector<vector<int>> adj(n+1);
        vector<vector<int>> baj(n+1);

        for (auto t : trust) {
            int a = t[0];
            int b = t[1];

            adj[b].push_back(a);
            baj[a].push_back(b);
        }

        for (int i = 1; i < adj.size(); i++) {
            vector<int> srcs = adj[i];
            if (srcs.size() != n - 1) continue;
            if (baj[i].size() != 0) continue;
            return i;
        }

        return -1;


        
    }
};