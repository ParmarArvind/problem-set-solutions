// method 2 using dfs
class Solution {
public:

    void dfs(unordered_map<int, vector<int>>& adj,
             vector<vector<int>>& result,
             int u) {

        while (!adj[u].empty()) {

            int v = adj[u].back();

            adj[u].pop_back();

            dfs(adj, result, v);

            result.push_back({u, v});
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;

        unordered_map<int, vector<int>> adj;

        // Build graph
        for (auto& p : pairs) {

            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);

            outDegree[u]++;
            inDegree[v]++;
        }

        // Default starting point
        int src = pairs[0][0];

        // Euler Path:
        // outDegree - inDegree = 1
        for (auto& it : outDegree) {

            int u = it.first;

            if (outDegree[u] - inDegree[u] == 1) {

                src = u;
                break;
            }
        }

        vector<vector<int>> result;

        dfs(adj, result, src);

        // DFS builds answer in reverse
        reverse(result.begin(), result.end());

        return result;
    }
};


// // method -1 using stack
// class Solution {
// public:
    
//     vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
//         unordered_map<int,int>InDegree;
//         unordered_map<int,int>OutDegree;
//         unordered_map<int,vector<int>>adj;
//         for(auto &p:pairs)
//         {
//             int u=p[0] ,v=p[1];
//             InDegree[v]++;
//             OutDegree[u]++;
//             adj[u].push_back(v);
//         }

//         // find src set default to first in case of euler circuit
//         int src=pairs[0][0]; 
//         for(auto & it:OutDegree)
//         {
//             int u=it.first;
//             int outD=it.second;
//             int inD=InDegree[u];
//             if(outD -inD ==1) 
//             {
//                 src=u;
//                 break;
//             }
//         }
        
//         stack<int>st;
//         vector<int>path;
//         st.push(src);
//         while(!st.empty())
//         {
//             int u=st.top();
            
//             if(!adj[u].empty())
//             {
//                 int v=adj[u].back();
//                 adj[u].pop_back();
//                 st.push(v);
//             }
//             else {
//                 path.push_back(u);
//                 st.pop();
//             }
//         }

//         reverse(path.begin(),path.end());
//         vector<vector<int>>result;
//         for(int i=0;i<path.size()-1;i++)
//         {
//             result.push_back({path[i],path[i+1]});
//         }
//         return result;
//     }
// };