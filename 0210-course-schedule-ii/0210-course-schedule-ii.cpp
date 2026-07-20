// method -2 using dfs
class Solution {
public:
    bool hasCycle;
    bool dfs(unordered_map<int,vector<int>>& adj,vector<bool> &visited,vector<bool>& inRecursion,stack<int>&st,int u)
    {
        visited[u]=true;
        inRecursion[u]=true;

        for(int v:adj[u])
        {
            if(inRecursion[v] ==true) {
                hasCycle=true;
            }
            if(!visited[v] ) 
                dfs(adj,visited,inRecursion,st,v);
        }

        inRecursion[u]=false;
        st.push(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // make graph .
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];

            adj[u].push_back(v);
        }
        hasCycle=false;
        vector<bool> visited(numCourses,0);
        vector<bool> inRecursion(numCourses,0);
        stack<int>st;

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            dfs(adj,visited,inRecursion,st,i) ;
        }
       if(hasCycle) return {};

       vector<int>result;
       while(!st.empty()) 
       {
        result.push_back(st.top());
        st.pop();
       }

        return result;
    }
};

// // method -1 BFS
// class Solution {
//   public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         // code here
//         vector<int>inDegree(numCourses,0);
//         unordered_map<int,vector<int>>adj;
//         for(auto &edge :prerequisites)
//         {
//             int v=edge[0];
//             int u=edge[1];
//             adj[u].push_back(v);
//             inDegree[v]++;
//         }
        
//         queue<int>que;
//         int count=0;
//         for(int i=0;i<numCourses;i++) 
//         {
//             if(inDegree[i]==0) {
//                 que.push(i);
//             }
//         }
        
//         vector<int>result;
//         while(!que.empty())
//         {
//             int u=que.front();
//             que.pop();
//             result.push_back(u);
//             for(auto & v:adj[u])
//             {
//                 inDegree[v]--;
                    
//                 if(inDegree[v]==0)
//                 {
//                     que.push(v);
//                 }
//             }
//         }
//         if(result.size()==numCourses) return result;
//         return  {};
//     }
// };