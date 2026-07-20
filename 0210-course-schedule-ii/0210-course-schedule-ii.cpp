
// method -1 BFS
class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // code here
        vector<int>inDegree(numCourses,0);
        unordered_map<int,vector<int>>adj;
        for(auto &edge :prerequisites)
        {
            int v=edge[0];
            int u=edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int>que;
        int count=0;
        for(int i=0;i<numCourses;i++) 
        {
            if(inDegree[i]==0) {
                que.push(i);
            }
        }
        
        vector<int>result;
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            result.push_back(u);
            for(auto & v:adj[u])
            {
                inDegree[v]--;
                    
                if(inDegree[v]==0)
                {
                    que.push(v);
                }
            }
        }
        if(result.size()==numCourses) return result;
        return  {};
    }
};