//method  bfs
class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int>&group,int source)
    {
         queue<pair<int,int>>que;
         group[source]=0;
         que.push({source, 0});
         while(!que.empty())
         {
            auto [u,prev]=que.front();
            group[u]=1-prev;
            que.pop();
            for(auto &v:graph[u])
            {
                if(group[v]==-1)
                {
                    que.push({v,group[u]});
                }
                else if(group[u]==group[v]) return false;
            }
         }
         return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();

        vector<int>group(n,-1);
        for(int i=0;i<n;i++) if(group[i]==-1 && bfs(graph,group,i)==false) return false;
        return true;

    }
};

// //method 1 dfs
// class Solution {
// public:
//     bool dfs(vector<vector<int>>& graph,vector<int>&group,int u, int prev)
//     {
//         if(prev==-1) group[u]=0;
//         else
//         group[u]=1-prev;

//         for(auto &v:graph[u])
//         {
//             if(group[v]==-1) 
//             {
//                 if(dfs(graph,group,v,group[u])==false) return false;
//             }
//             else if(group[u]==group[v]) return false;
//         }

//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();

//         vector<int>group(n,-1);
//         for(int i=0;i<n;i++) if(group[i]==-1 && dfs(graph,group,i,-1)==false) return false;
//         return true;
//     }
// };

 