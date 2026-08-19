class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        //adj list creation
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<n;i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++)
            {
                int x2=points[j][0];
                int y2=points[j][1];

                int wt=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }

        // prim's algorithm
        int sum=0;
        vector<int>visited(n,false);
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>>pq;
        
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int u=pq.top().second;
    
            pq.pop();
            
            if(!visited[u])
            {
                visited[u]=true;
                sum+=wt;
                
                for(auto &it:adj[u])
                {
                    int v=it.first;
                    int w=it.second;
                    
                    pq.push({w,v});
                }
            }
        }

        return sum;
    }
};