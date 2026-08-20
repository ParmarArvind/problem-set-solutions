class Solution {
public:
    pair<int,int> BFS(unordered_map<int ,vector<int>>& adj,int source)
    {
        queue<int> q;
        q.push(source);

        int dist=0;
        int farthest=0;
        unordered_map<int,bool> visited;
        visited[source]=true;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                int u=q.front();
                q.pop();
                for(auto & v:adj[u])
                {
                    if(visited[v]==false)
                    {
                        visited[v]=true;
                        q.push(v);
                        farthest=v;
                    }
                }
            }
            if(!q.empty()) dist++;
        }

        return {farthest , dist};
    }

    int findDia(unordered_map<int ,vector<int>>& adj , int source)
    {
        // pick a random node and find the farthest node from that and that node is the one end point of the diameter
        auto[farthest,dist]=BFS(adj,0);

        // now find the another node from the farthest node

         auto[anotherFarthest,distance]=BFS(adj,farthest);

         return distance;
    }
    

    unordered_map<int ,vector<int>> build(vector<vector<int>>& edges){
        unordered_map<int ,vector<int>> adj;
        for(auto& edge:edges)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int ,vector<int>> adj1 =build(edges1);
        unordered_map<int ,vector<int>> adj2 =build(edges2);

        int d1=findDia(adj1,0);
        int d2=findDia(adj2,0);

        int combinedDia=(d1+1)/2+ (d2+1)/2 +1 ;

        return max({d1,d2,combinedDia});
    }
};


// class Solution {
// public:
//     int findDia(unordered_map<int, vector<int>>& adj, int src, int& firstEnd,int n) {

//         queue<int> que;
//         vector<bool> visited(n, false);

//         que.push(src);
//         visited[src] = true;

//         int level = 0;

//         while (!que.empty()) {

//             int size = que.size();
//             int lastNode = -1;

//             while (size--) {

//                 int u = que.front();
//                 que.pop();

//                 lastNode = u;

//                 for (auto& v : adj[u]) {

//                     if (!visited[v]) {

//                         que.push(v);
//                         visited[v] = true;
//                     }
//                 }
//             }

//             firstEnd = lastNode;
//             level++;
//         }

//         // diameter is number of edges i.e. level-1
//         return level - 1;
//     }

//     int minimumDiameterAfterMerge(vector<vector<int>>& edges1,vector<vector<int>>& edges2) {

//         int n = edges1.size() +1;
//         int m = edges2.size()+1 ;

//         unordered_map<int, vector<int>> adj1;
//         unordered_map<int, vector<int>> adj2;

//         // Tree 1
//         for (auto& e : edges1) {

//             int u = e[0];
//             int v = e[1];

//             adj1[u].push_back(v);
//             adj1[v].push_back(u);
//         }

//         // Tree 2
//         for (auto& e : edges2) {

//             int u = e[0];
//             int v = e[1];

//             adj2[u].push_back(v);
//             adj2[v].push_back(u);
//         }

//         int firstEnd;
//         int secondEnd;

//         // Find diameter of tree 1
//         findDia(adj1, 0, firstEnd, n);
//         int diameter1 = findDia(adj1, firstEnd, secondEnd, n);

//         // Find diameter of tree 2
//         findDia(adj2, 0, firstEnd, m);
//         int diameter2 = findDia(adj2, firstEnd, secondEnd, m);

//         int radius1 = (diameter1 + 1) / 2;
//         int radius2 = (diameter2 + 1) / 2;

//         return max({diameter1, diameter2, radius1 + radius2 + 1});
//     }
// };