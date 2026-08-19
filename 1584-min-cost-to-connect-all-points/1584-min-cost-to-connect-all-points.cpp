
// kruskal's algorihtm wihtout DSU  TC=(ElogE +E(V+E))
class Solution {
public:

    // Check whether adding edge (u, v) creates a cycle
    bool hasCycle(int u, int v, vector<vector<int>>& adj, int n) {
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(u);
        visited[u] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == v)
                return true;

            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }

        return false;
    }

    int kruskalAlgo(int n, vector<vector<int>>& edges) {

        // Sort edges by weight
        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[2] < b[2];
            });

        vector<vector<int>> adj(n);

        int mstWeight = 0;
        int edgesUsed = 0;

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // If u and v are already connected,
            // adding this edge creates a cycle
            if (!hasCycle(u, v, adj, n)) {

                adj[u].push_back(v);
                adj[v].push_back(u);

                mstWeight += wt;
                edgesUsed++;

                if (edgesUsed == n - 1)
                    break;
            }
        }

        return mstWeight;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        //adj list creation
        vector<vector<int>>edges;;
        for(int i=0;i<n;i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            vector<int>temp;
            for(int j=i+1;j<n;j++)
            {
                int x2=points[j][0];
                int y2=points[j][1];

                int wt=abs(x1-x2)+abs(y1-y2);
                temp={i,j,wt};
                edges.push_back(temp);
            }
        }

        return kruskalAlgo(n,edges);
    }
};



// // method -2 kruskal's algorithm
// class Solution {
// public:

//     vector<int>rank;
//     vector<int>parent;
//     int find(int x)
//     {
//         if(x==parent[x]) return x;
//         return parent[x]=find(parent[x]);
//     }
//     void Union(int x,int y)
//     {
//         int xParent=find(x);
//         int yParent=find(y);
//         if(xParent==yParent) return;
        
//         if(rank[xParent]<rank[yParent])
//         {
//             parent[xParent]=yParent;
//         }
//         else if(rank[yParent]<rank[xParent])
//         {
//             parent[yParent]=xParent;
//         }
//         else {
//             parent[xParent]=yParent;
//             rank[yParent]++;
//         }
//     }
//     int kruskalAlgo(vector<vector<int>>& edges)
//     {
//         int sum=0;
//         for(auto &e:edges)
//         {
//             int u=e[0];
//             int v=e[1];
//             int w=e[2];
            
//             int uParent=find(u);
//             int vParent=find(v);
//             if(uParent==vParent) continue; //connected
//             // not connected , so connect them
//             Union(u,v);
//             // add to sum
//             sum+=w;
//         }
        
//         return sum;
//     }
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n=points.size();
//         //adj list creation
//         vector<vector<int>>edges;;
//         for(int i=0;i<n;i++)
//         {
//             int x1=points[i][0];
//             int y1=points[i][1];
//             vector<int>temp;
//             for(int j=i+1;j<n;j++)
//             {
//                 int x2=points[j][0];
//                 int y2=points[j][1];

//                 int wt=abs(x1-x2)+abs(y1-y2);
//                 temp={i,j,wt};
//                 edges.push_back(temp);
//             }
//         }

//         auto lambda=[&](auto &a ,auto &b){
//             return a[2]<b[2];
//         };
//         sort(edges.begin() ,edges.end(),lambda);
        
//         rank.resize(n,1);
//         parent.resize(n);
//         for(int i=0;i<n;i++) parent[i]=i;
        
//         return kruskalAlgo(edges);

//     }
// };

// // method -1  prim's algorithm   TC=(Elog(E))
// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n=points.size();
//         //adj list creation
//         unordered_map<int,vector<pair<int,int>>>adj;
//         for(int i=0;i<n;i++)
//         {
//             int x1=points[i][0];
//             int y1=points[i][1];
//             for(int j=i+1;j<n;j++)
//             {
//                 int x2=points[j][0];
//                 int y2=points[j][1];

//                 int wt=abs(x1-x2)+abs(y1-y2);
//                 adj[i].push_back({j,wt});
//                 adj[j].push_back({i,wt});
//             }
//         }

//         // prim's algorithm
//         int sum=0;
//         vector<int>visited(n,false);
        
//         priority_queue<
//             pair<int,int>,
//             vector<pair<int,int>>,
//             greater<pair<int,int>>>pq;
        
//         pq.push({0,0});
        
//         while(!pq.empty())
//         {
//             int wt=pq.top().first;
//             int u=pq.top().second;
    
//             pq.pop();
            
//             if(!visited[u])
//             {
//                 visited[u]=true;
//                 sum+=wt;
                
//                 for(auto &it:adj[u])
//                 {
//                     int v=it.first;
//                     int w=it.second;
                    
//                     pq.push({w,v});
//                 }
//             }
//         }

//         return sum;
//     }
// };