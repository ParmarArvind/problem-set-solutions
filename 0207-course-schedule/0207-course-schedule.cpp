class Solution {
public:
// using dfs
    bool dfs(unordered_map<int,vector<int>>& adj,vector<bool> &visited,vector<bool>& inRecursion,int u)
    {
        visited[u]=true;
        inRecursion[u]=true;

        for(int v:adj[u])
        {
            if(inRecursion[v] ==true) return true;
            if(!visited[v] && dfs(adj,visited,inRecursion,v))
                return true;
            
        }
        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // make graph .
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses,0);
        vector<bool> inRecursion(numCourses,0);

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i] && dfs(adj,visited,inRecursion,i) ) return false;
        }

        
        return true;
        
    }
};