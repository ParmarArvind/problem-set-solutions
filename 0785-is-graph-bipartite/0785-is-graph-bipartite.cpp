class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>&group,int u, int prev)
    {
        if(prev==-1) group[u]=0;
        else
        group[u]=1-prev;

        for(auto &v:graph[u])
        {
            if(group[v]==-1) 
            {
                if(dfs(graph,group,v,group[u])==false) return false;
            }
            else if(group[u]==group[v]) return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>group(n,-1);
        for(int i=0;i<n;i++) if(group[i]==-1 && dfs(graph,group,i,-1)==false) return false;
        return true;
    }
};

 