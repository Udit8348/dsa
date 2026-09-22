class Solution {
public:
    // process times into an adjacency list (with to,weight pairs)
    vector<vector<pair<int,int>>> build_adj_list(size_t n, vector<vector<int>>& times) {
        vector<vector<pair<int,int>>> adj_list(n+1); // alloc n empty vectors which we can push to

        for (vector<int> tup : times) {
            int u = tup[0];
            int v = tup[1];
            int w = tup[2];

            adj_list[u].emplace_back(w,v);
        }
        return adj_list;
    }


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int res = -1;
        int global_time = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // (w,n)
        
        vector<vector<pair<int,int>>> adj_list = build_adj_list(n, times);
        vector<bool> visited (n+1, false);

        pq.push({0,k});
        
        while(!pq.empty()) {
            // here edge implies a dest we are attempting to visit
            auto edge = pq.top();
            pq.pop();

            int w = edge[0];
            int v = edge[1];

            if (visited[v]) continue;

            global_time = w;
            visited[v] = true;

            if (adj_list[v].size() > 0) {
                for (auto& e : adj_list[v]) {
                    int w_next = e.first;
                    int v_next = e.second;

                    if (!visited[v_next]) {
                        pq.push({w + w_next, v_next});
                    }
                }
            }
        }

        // skip first century node
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) return -1;
        }

        return global_time;
    }
};
