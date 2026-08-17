class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // Create adjacency list.
        unordered_map<int,vector<pair<int, int>>> adj;

        for (auto &edge : times) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        // Distance array.
        vector<int> dist(n +1, INT_MAX);

        // Min-heap storing {distance, node}.
        priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        // Dijkstra from destination.
        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int u = curr.second;
            
            for (auto &it : adj[u]) 
            {
                int v = it.first;
                int wt = it.second;

                if (d + wt < dist[v]) {

                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        
        dist[0]=0;
        int result=*max_element(dist.begin(), dist.end());
        if(result==INT_MAX) return -1;
        return result;
    }
};
