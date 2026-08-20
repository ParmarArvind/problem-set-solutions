// method -1 using stack
class Solution {
public:
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        unordered_map<int,int>InDegree;
        unordered_map<int,int>OutDegree;
        unordered_map<int,vector<int>>adj;
        for(auto &p:pairs)
        {
            int u=p[0] ,v=p[1];
            InDegree[v]++;
            OutDegree[u]++;
            adj[u].push_back(v);
        }

        // find src set default to first in case of euler circuit
        int src=pairs[0][0]; 
        for(auto & it:OutDegree)
        {
            int u=it.first;
            int outD=it.second;
            int inD=InDegree[u];
            if(outD -inD ==1) 
            {
                src=u;
                break;
            }
        }
        
        stack<int>st;
        vector<int>path;
        st.push(src);
        while(!st.empty())
        {
            int u=st.top();
            
            if(!adj[u].empty())
            {
                int v=adj[u].back();
                adj[u].pop_back();
                st.push(v);
            }
            else {
                path.push_back(u);
                st.pop();
            }
        }

        reverse(path.begin(),path.end());
        vector<vector<int>>result;
        for(int i=0;i<path.size()-1;i++)
        {
            result.push_back({path[i],path[i+1]});
        }
        return result;
    }
};