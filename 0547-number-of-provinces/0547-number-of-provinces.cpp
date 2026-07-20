// method -2 BFS
class Solution {
public:
    int n;
    void bfs(vector<vector<int>>& isConnected, vector<bool>&visited,int source)
    {
        queue<int>que;
        que.push(source);
        visited[source]=true;

        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int v=0 ;v<n;v++)
            {
                if(isConnected[u][v])
                {
                    if(!visited[v])
                    {
                        que.push(v);
                        visited[v]=true;
                    }
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         n=isConnected.size();
        
        int result=0;
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bfs(isConnected,visited,i);
                result++;
            }
        }
        return result;        
    }
};

// // method -1 without adj making , use of the given vector
// class Solution {
// public:
// int n;
// void dfs(vector<vector<int>>& isConnected,vector<bool>&visited,int u)
// {
//     visited[u]=1;
//     for(int v=0;v<n;v++)
//     {
//         if(!visited[v] && isConnected[u][v]) dfs(isConnected,visited,v);
//     }
// }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//          n=isConnected.size();
        
//         int result=0;
//         vector<bool>visited(n,0);
//         for(int i=0;i<n;i++)
//         {
//             if(!visited[i])
//             {
//                 dfs(isConnected,visited,i);
//                 result++;
//             }
//         }
//         return result;        
//     }
// };
// // method -1 using dfs
// class Solution {
//   public:
//     void DFS( unordered_map<int,vector<int>>&adj,vector<bool>&visited,int u)
//     {
//         visited[u]=true;
//         for(auto &v:adj[u])
//         {
//             if(!visited[v])
//             {
//                 DFS(adj,visited,v);
//             }
//         }
//     }
    
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         // code here
//         int V=isConnected.size();
//         unordered_map<int,vector<int>>adj;
//         for(int u=0;u<V;u++)
//         {
//             for(int v=0;v<V;v++)
//             {
//                 if(isConnected[u][v])
//                 {
//                     adj[u].push_back(v);
//                     adj[v].push_back(u);
//                 }
//             }
//         }
        
//         int result=0;
        
//         vector<bool>visited(V,false);
        
//         for(int u=0;u<V;u++)
//         {
//             if(!visited[u]){
//                 DFS(adj,visited,u);
//                 result++;
//             }
//         }
        
        
//         return result;
//     }
// };