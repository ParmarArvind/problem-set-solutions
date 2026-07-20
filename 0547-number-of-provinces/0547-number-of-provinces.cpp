
// method -1 using dfs
class Solution {
  public:
    void DFS( unordered_map<int,vector<int>>&adj,vector<bool>&visited,int u)
    {
        visited[u]=true;
        for(auto &v:adj[u])
        {
            if(!visited[v])
            {
                DFS(adj,visited,v);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        // code here
        int V=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++)
        {
            for(int v=0;v<V;v++)
            {
                if(isConnected[u][v])
                {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        
        int result=0;
        
        vector<bool>visited(V,false);
        
        for(int u=0;u<V;u++)
        {
            if(!visited[u]){
                DFS(adj,visited,u);
                result++;
            }
        }
        
        
        return result;
    }
};